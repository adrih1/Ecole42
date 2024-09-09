/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:46:10 by ahors             #+#    #+#             */
/*   Updated: 2024/09/09 10:48:58 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	ft_clean_program(t_program *program)
{
	t_philosopher	*philo;
	int				i;

	i = 0;
	while (i < program->philo_nbr)
	{
		philo = program->philos + i;
		pthread_mutex_destroy(&philo->philo_mutex);
	}
	pthread_mutex_destroy(&program->write_mutex);
	pthread_mutex_destroy(&program->dead_mutex);
	free(program->forks);
	free(program->philos);
}
