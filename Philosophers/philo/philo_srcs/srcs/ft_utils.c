/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:49:52 by adrienhors        #+#    #+#             */
/*   Updated: 2024/06/12 17:20:28 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_length_of_char_array(char **av)
{
	int	length;

	length = 0;
	while (av[length] != NULL)
		length++;
	return (length);
}

long	ft_get_time(int time_code)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		ft_error_exit("Get time of day failed.\n");
	if (MILISECOND == time_code)
		return (tv.tv_sec * 1e3 + tv.tv_usec / 1e3);
	else if (MICROSECOND == time_code)
		return (tv.tv_sec * 1e6 + tv.tv_usec);
	else if (SECOND == time_code)
		return (tv.tv_sec + tv.tv_usec / 1e6);
	else
		ft_error_exit("Wrong input to gettime:"
			"use <MILLISECOND> <MICROSECOND> <SECONDS>");
	return (1337);
}

void	ft_precise_usleep(long usec, t_program *program)
{
	long start;
	long elapsed;
	long rem;

	start = ft_get_time(MICROSECOND);
	while (ft_get_time(MICROSECOND) - start < usec)
	{
		if (ft_simulation_finished(program))
			break ;
		elapsed = ft_get_time(MICROSECOND) - start;
		rem = usec - elapsed;
		if (rem > 1e4)
			usleep(rem / 2);
		else
		{
			while (ft_get_time(MICROSECOND) - start < usec)
				;
		}
	}
}


void	ft_clean_program(t_program *program)
{
	t_philosopher *philo; 
	int i; 

	i = -1; 
	while(++i < program->philo_nbr)
	{
		philo = program->philos + i; 
		ft_safe_mutex_handle(&philo->philo_mutex, DESTROY); 
	}
	ft_safe_mutex_handle(&program->write_mutex, DESTROY); 
	ft_safe_mutex_handle(&program->program_mtx, DESTROY); 
	free(program->forks); 
	free(program->philos); 
}