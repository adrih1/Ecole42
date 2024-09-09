/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:02:01 by ahors             #+#    #+#             */
/*   Updated: 2024/09/09 10:41:09 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_error_exit(const char *error)
{
	printf(RED "🚨 %s 🚨\n" RESET, error);
	return (1);
}

void	ft_write_status(t_philosopher *philo, const char *status)
{
	long	current_time;

	current_time = ft_get_current_time_in_ms();
	pthread_mutex_lock(&philo->program->write_mutex);
	pthread_mutex_lock(&philo->program->dead_mutex);
	if (!philo->program->is_dead)
		printf("%ld %d %s\n", current_time - philo->program->start_simulation,
			philo->id, status);
	pthread_mutex_unlock(&philo->program->dead_mutex);
	pthread_mutex_unlock(&philo->program->write_mutex);
}
