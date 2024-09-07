/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:06:56 by ahors             #+#    #+#             */
/*   Updated: 2024/09/07 18:56:48 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static int ft_monitor_check_philo_dead(t_philosopher *philo)
{
    bool has_died; 

    has_died = false; 
	pthread_mutex_lock(&philo->philo_mutex);
    if ((ft_get_current_time_in_ms() - philo->last_meal_time > philo->program->time_to_die) && (!philo->is_full))
    {
        ft_write_status(philo, "philo died");
        pthread_mutex_lock(&philo->program->dead_mutex); 
        philo->program->is_dead = true; 
        pthread_mutex_unlock(&philo->program->dead_mutex); 
        has_died=true; 
    }
    pthread_mutex_unlock(&philo->philo_mutex);
    return has_died;
}


void    ft_monitor(t_program *program)
{
    int i; 
	while (1)
	{   
        i = 0; 

		while (i < program->philo_nbr)
		{
            if(ft_monitor_check_philo_dead(&program->philos[i]))
				return;
            pthread_mutex_lock(&program->philos[i].philo_mutex); 
            if(program->philos[i].is_full)
                program->philos_full++; 
            pthread_mutex_unlock(&program->philos[i].philo_mutex); 
			i++;
		}

        // Check global | Si nb de philo = nb de philo full 
        if(program->philo_nbr == program->philos_full)
			return;

		ft_usleep(2000);
	}
}