/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:09:16 by ahors             #+#    #+#             */
/*   Updated: 2024/06/14 14:09:36 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	ft_thinking(t_philosopher *philo, bool pre_simulation)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	if (!pre_simulation)
		ft_write_status(THINKING, philo, DEBUG_MODE);
	if (philo->program->philo_nbr % 2 == 0)
		return ;
	t_eat = philo->program->time_to_eat;
	t_sleep = philo->program->time_to_sleep;
	t_think = (t_eat * 2) - t_sleep;
	if (t_think < 0)
		t_think = 0;
	ft_precise_usleep(t_think * 0.42, philo->program);
}

void	*ft_lone_philo(void *data)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)data;
	ft_wait_all_threads(philo->program);
	ft_set_long(&philo->philo_mutex, &philo->last_meal_time,
		ft_get_time(MILISECOND));
	ft_increase_long(&philo->program->program_mtx,
		&philo->program->nbr_threads_running);
	ft_write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	while (!ft_simulation_finished(philo->program))
		ft_precise_usleep(200, philo->program);
	return (NULL);
}

void	ft_eat(t_philosopher *philo)
{
	ft_safe_mutex_handle(&philo->first_fork->fork, LOCK);
	ft_write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	ft_safe_mutex_handle(&philo->second_fork->fork, LOCK);
	ft_write_status(TAKE_SECOND_FORK, philo, DEBUG_MODE);
	ft_set_long(&philo->philo_mutex, &philo->last_meal_time,
		ft_get_time(MILISECOND));
	philo->meals_eaten++;
	ft_write_status(EATING, philo, DEBUG_MODE);
	ft_precise_usleep(philo->program->time_to_eat, philo->program);
	if (philo->program->nb_limit_meals > 0
		&& (philo->meals_eaten == philo->program->nb_limit_meals))
		ft_set_bool(&philo->philo_mutex, &philo->full, true);
	ft_safe_mutex_handle(&philo->first_fork->fork, UNLOCK);
	ft_safe_mutex_handle(&philo->second_fork->fork, UNLOCK);
}

void	*ft_simulation(void *data)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)data;
	ft_wait_all_threads(philo->program);
	ft_set_long(&philo->philo_mutex, &philo->last_meal_time,
		ft_get_time(MILISECOND));
	ft_increase_long(&philo->program->program_mtx,
		&philo->program->nbr_threads_running);
	ft_desynchronize_philos(philo);
	while (!ft_simulation_finished(philo->program))
	{
		if (ft_get_bool(&philo->philo_mutex, &philo->full))
			break ;
		ft_eat(philo);
		ft_write_status(SLEEPING, philo, DEBUG_MODE);
		ft_precise_usleep(philo->program->time_to_sleep, philo->program);
		ft_thinking(philo, false);
	}
	return (NULL);
}

void	ft_simulation_start(t_program *program)
{
	int	i;

	i = -1;
	if (program->nb_limit_meals == 0)
		return ;
	else if (program->philo_nbr == 1)
		ft_safe_thread_handle(&program->philos[0].thread_id, ft_lone_philo,
			&program->philos[0], CREATE);
	else
		while (++i < program->philo_nbr)
			ft_safe_thread_handle(&program->philos[i].thread_id, ft_simulation,
				&program->philos[i], CREATE);
	ft_safe_thread_handle(&program->monitor, ft_monitor_simulation, program,
		CREATE);
	program->start_simulation = ft_get_time(MILISECOND);
	ft_set_bool(&program->program_mtx, &program->all_threads_ready, true);
	i = -1;
	while (++i < program->philo_nbr)
		ft_safe_thread_handle(&program->philos[i].thread_id, NULL, NULL, JOIN);
	ft_set_bool(&program->program_mtx, &program->end_simulation, true);
	ft_safe_thread_handle(&program->monitor, NULL, NULL, JOIN);
}
