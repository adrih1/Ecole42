/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:49:52 by adrienhors        #+#    #+#             */
/*   Updated: 2024/06/10 16:21:58 by adrienhors       ###   ########.fr       */
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

long	ft_get_time(t_time_code time_code)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL))
		ft_error_exit("Get time of day failed.\n");
	if (SECOND == time_code)
		return (current_time.tv_sec + (current_time.tv_usec / 1e6));
	else if (MILISECOND == time_code)
		return (current_time.tv_sec * 1e3 + (current_time.tv_usec / 1e3));
	else if (MICROSECOND == time_code)
		return (current_time.tv_sec * 1e6 + current_time.tv_usec);
	else
		ft_error_exit("Wrong input for gettime.\n");
	return (263);
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
		if ((rem / 2) > 1e3)
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