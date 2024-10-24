/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:09:16 by ahors             #+#    #+#             */
/*   Updated: 2024/10/24 10:36:17 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	ft_philo_takes_forks(t_philosopher *philo)
{
		pthread_mutex_lock(&philo->second_fork->fork);
		pthread_mutex_lock(&philo->first_fork->fork);
		ft_write_status(philo, "has taken a fork");
}

void	ft_philo_puts_forks(t_philosopher *philo)
{

		pthread_mutex_unlock(&philo->first_fork->fork);
		pthread_mutex_unlock(&philo->second_fork->fork);
}

void	ft_philo_eats(t_philosopher *philo)
{
	ft_write_status(philo, "is eating");
	pthread_mutex_lock(&philo->philo_mutex);
	philo->last_meal_time = ft_get_current_time_in_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->philo_mutex);
	ft_usleep(philo->program->time_to_eat);
}

void	ft_philo_sleeps(t_philosopher *philo)
{
	ft_write_status(philo, "is sleeping");
	ft_usleep(philo->program->time_to_sleep);
}

void	*ft_dinner(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(50);
	while (1)
	{
		if (ft_check_philo_is_dead(philo) || ft_check_philo_is_full(philo))
			break ;
		ft_philo_takes_forks(philo);
		ft_philo_eats(philo);
		ft_philo_puts_forks(philo);
		if (ft_check_philo_is_dead(philo))
			break ;
		ft_philo_sleeps(philo);
		ft_write_status(philo, "is thinking");
	}
	return (NULL);
}
