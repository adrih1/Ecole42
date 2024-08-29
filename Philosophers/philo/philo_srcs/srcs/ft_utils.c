/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:49:52 by adrienhors        #+#    #+#             */
/*   Updated: 2024/08/29 15:07:27 by adrienhors       ###   ########.fr       */
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

long ft_get_current_time_in_ms(void)
{
	struct timeval current_time;
	
	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
}

void ft_usleep(long time_in_ms)
{
	long start_time = ft_get_current_time_in_ms();
	long end_time = start_time + time_in_ms;
	while (ft_get_current_time_in_ms() < end_time)
		usleep(100);
}



int	ft_check_philo_is_dead(t_philosopher *philo)
{

	pthread_mutex_lock(&philo->program->dead_mutex);
	if (philo->program->is_dead)
	{
		pthread_mutex_unlock(&philo->program->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->program->dead_mutex);
	return (0);
}


int	ft_check_philo_is_full(t_philosopher *philo)
{
	if(philo->program->nb_limit_meals != -1 && (philo->meals_eaten >= philo->program->nb_limit_meals))
	{
		ft_write_status(philo, "is full");
		pthread_mutex_lock(&philo->philo_mutex);
		philo->is_full = true;
		pthread_mutex_unlock(&philo->philo_mutex);
		return (1);
	}
	return (0); 
}

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
