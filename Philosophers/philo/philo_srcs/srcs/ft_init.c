/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:08:45 by ahors             #+#    #+#             */
/*   Updated: 2024/06/14 14:09:00 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

// Si philo impair --> first fork is the left
// Si philo pair --> first fork is the right
// Even philosopher takes the 1st fork
void	ft_assign_forks(t_philosopher *philo, t_fork *forks, int philo_position)
{
	int	philo_nbr;

	philo_nbr = philo->program->philo_nbr;
	philo->first_fork = &forks[(philo_position + 1) % philo_nbr];
	philo->second_fork = &forks[philo_position];
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[philo_position];
		philo->second_fork = &forks[(philo_position + 1) % philo_nbr];
	}
}

void	ft_philo_init(t_program *program)
{
	int				i;
	t_philosopher	*philo;

	i = -1;
	while (++i < program->philo_nbr)
	{
		philo = program->philos + i;
		philo->id = i + 1;
		philo->meals_eaten = 0;
		philo->full = false;
		ft_safe_mutex_handle(&philo->philo_mutex, INIT);
		philo->program = program;
		ft_assign_forks(philo, program->forks, i);
	}
}

void	ft_data_init(t_program *program)
{
	int	i;

	i = -1;
	program->end_simulation = false;
	program->all_threads_ready = false;
	program->nbr_threads_running = 0;
	program->philos = ft_safe_malloc(sizeof(t_philosopher)
			* program->philo_nbr);
	program->forks = ft_safe_malloc(sizeof(t_fork) * program->philo_nbr);
	ft_safe_mutex_handle(&program->write_mutex, INIT);
	ft_safe_mutex_handle(&program->program_mtx, INIT);
	while (++i < program->philo_nbr)
	{
		ft_safe_mutex_handle(&program->forks[i].fork, INIT);
		program->forks[i].fork_id = i;
	}
	ft_philo_init(program);
}
