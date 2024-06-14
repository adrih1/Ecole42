/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:06:56 by ahors             #+#    #+#             */
/*   Updated: 2024/06/14 14:08:28 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static bool	ft_philo_died(t_philosopher *philo)
{
	long	elapsed;
	long	time_to_die;

	if (ft_get_bool(&philo->philo_mutex, &philo->full))
		return (false);
	elapsed = ft_get_time(MILISECOND) - ft_get_long(&philo->philo_mutex,
			&philo->last_meal_time);
	time_to_die = philo->program->time_to_die / 1e3;
	if (elapsed > time_to_die)
		return (true);
	return (false);
}

void	*ft_monitor_simulation(void *data)
{
	int			i;
	t_program	*program;

	program = (t_program *)data;
	while (!ft_all_threads_are_running(&program->program_mtx,
			&program->nbr_threads_running, program->philo_nbr))
		;
	while (!ft_simulation_finished(program))
	{
		i = -1;
		while (++i < program->philo_nbr && !ft_simulation_finished(program))
		{
			if (ft_philo_died(program->philos + i))
			{
				ft_set_bool(&program->program_mtx, &program->end_simulation,
					true);
				ft_write_status(DIED, program->philos + i, DEBUG_MODE);
			}
		}
	}
	return (NULL);
}
