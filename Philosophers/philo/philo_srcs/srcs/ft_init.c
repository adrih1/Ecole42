/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:08:45 by ahors             #+#    #+#             */
/*   Updated: 2024/08/29 15:15:41 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"


int ft_init_forks(t_fork *forks, int nb_philo)
{
	int i; 
	
	i = 0;  
	while (i < nb_philo)
	{
		if (pthread_mutex_init(&forks[i].fork, NULL) != 0)
		{
			ft_error_exit("Initializing fork mutex");
		}
		forks[i].fork_id = i + 1;
		i++;
	}
	return (0);
}

// Si philo impair --> first fork is the left
// Si philo pair --> first fork is the right
void	ft_init_philosophers(t_philosopher *philos, t_fork *forks, t_program *program)
{
	int				i;

	i = 0;
	program->start_simulation = ft_get_current_time_in_ms();
	while (i < program->philo_nbr)
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].is_full = false;
		philos[i].last_meal_time = ft_get_current_time_in_ms();
		philos[i].first_fork = &forks[i];
		philos[i].second_fork = &forks[(i + 1) % program->philo_nbr];
		philos[i].program = program;
		pthread_mutex_init(&philos[i].philo_mutex, NULL); 
		i++;
	}
}
int ft_create_philosopher_threads(t_philosopher *philos, int nb_philo)
{
	int i;

	i = 0; 
	while (i < nb_philo)
	{
		if (pthread_create(&philos[i].thread_id, NULL, ft_dinner, &philos[i]) != 0)
			return ft_error_exit("Creating thread for philosopher");
		i++;
	}
	return (0);
}

 
int	ft_data_init(t_program *program)
{

	if (pthread_mutex_init(&program->write_mutex, NULL) != 0)
		return ft_error_exit("Initializing program write mutex");

	if (pthread_mutex_init(&program->dead_mutex, NULL) != 0)
		return ft_error_exit("Initializing dead philo mutex");
		
	program->forks = malloc(sizeof(t_fork) * program->philo_nbr);
	if (!program->forks)
		return ft_error_exit("Allocating memory for forks");

	if (ft_init_forks(program->forks, program->philo_nbr) != 0)
		return (1);

	program->philos = malloc(sizeof(t_philosopher) * program->philo_nbr);
	if (!program->philos)
		return ft_error_exit("Allocating memory for philosophers");

	ft_init_philosophers(program->philos, program->forks, program);
	if (program->philo_nbr == 1)
	{
		// ft_single_philosopher_simulation(&table->philos[0]); //TODO
		return (0);
	}
	if (ft_create_philosopher_threads(program->philos, program->philo_nbr) != 0)
		return 1;
	return (0); 
}
