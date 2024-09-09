/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:46:10 by ahors             #+#    #+#             */
/*   Updated: 2024/09/09 14:32:14 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	ft_join_threads(t_program *program)
{
	int i; 

	i = 0;
	while (i < program->philo_nbr)
	{
		if (program->philos[i].thread_id)
		{
			pthread_join(program->philos[i].thread_id, NULL);
		
		}
		i++;
	}
	
}

void	ft_destroy_mutex(t_program *program)
{
	int				i;

	i = 0;
	while (i < program->philo_nbr)
	{
		pthread_mutex_destroy(&program->philos[i].philo_mutex);
		i++;
	}
	i = 0;
	while (i < program->philo_nbr)
	{
		pthread_mutex_destroy(&program->forks[i].fork);
		i++;
	}
	pthread_mutex_destroy(&program->write_mutex);
	pthread_mutex_destroy(&program->dead_mutex);
}


void	ft_clean_program(t_program *program)
{
	ft_join_threads(program);
	ft_destroy_mutex(program);
	free(program->forks);
	free(program->philos);
}
