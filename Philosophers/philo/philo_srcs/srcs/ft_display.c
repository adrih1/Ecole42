/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:02:01 by ahors             #+#    #+#             */
/*   Updated: 2024/08/28 12:35:13 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_error_exit(const char *error)
{
	printf(RED "🚨 %s 🚨\n" RESET, error);
	return (1);
}

// void	ft_write_status_debug(t_philo_status status, t_philosopher *philo,
// 		long elapsed)
// {
// 	if (TAKE_FIRST_FORK == status && !ft_simulation_finished(philo->program))
// 		printf("%6ld %d has taken the 1st fork 🍽\t\t\tn°[%d]\n", elapsed,
// 			philo->id, philo->first_fork->fork_id);
// 	else if (TAKE_SECOND_FORK == status
// 		&& !ft_simulation_finished(philo->program))
// 		printf("%6ld %d has taken the 2nd fork 🍽\t\t\tn°[%d]\n", elapsed,
// 			philo->id, philo->second_fork->fork_id);
// 	else if (EATING == status && !ft_simulation_finished(philo->program))
// 		printf("%6ld %d is eating 🍝\t\t\t[🍝 %ld 🍝]\n", elapsed, philo->id,
// 			philo->meals_eaten);
// 	else if (SLEEPING == status && !ft_simulation_finished(philo->program))
// 		printf("%6ld %d is sleeping 😴\n", elapsed, philo->id);
// 	else if (THINKING == status && !ft_simulation_finished(philo->program))
// 		printf("%6ld %d is thinking 🤔\n", elapsed, philo->id);
// 	else if (DIED == status)
// 		printf("💀💀💀 %6ld %d died   💀💀💀\n", elapsed, philo->id);
// }

void	ft_write_status(t_philo_status status, t_philosopher *philo, bool debug)
{
	long	elapsed;

	elapsed = ft_get_time(MILISECOND) - philo->program->start_simulation;
	if (philo->full)
		return ;
	ft_safe_mutex_handle(&philo->program->write_mutex, LOCK);
	if (debug)
		ft_write_status_debug(status, philo, elapsed);
	else
	{
		if ((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status)
			&& !ft_simulation_finished(philo->program))
			printf("%-6ld %d has taken a fork\n", elapsed, philo->id);
		else if (EATING == status && !ft_simulation_finished(philo->program))
			printf("%-6ld %d is eating.\n", elapsed, philo->id);
		else if (SLEEPING == status && !ft_simulation_finished(philo->program))
			printf("%-6ld %d is sleeping.\n", elapsed, philo->id);
		else if (THINKING == status && !ft_simulation_finished(philo->program))
			printf("%-6ld %d is thinking.\n", elapsed, philo->id);
		else if (DIED == status)
			printf("%-6ld %d died.\n", elapsed, philo->id);
	}
	ft_safe_mutex_handle(&philo->program->write_mutex, UNLOCK);
}
