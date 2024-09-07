/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:09:03 by ahors             #+#    #+#             */
/*   Updated: 2024/09/07 18:35:36 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

// Fonction d'affichage
void	ft_printf_args(t_program *program)
{
	printf("Time to die: %ld\n", program->time_to_die); 
	printf("Time to eat: %ld\n", program->time_to_eat); 
	printf("Time to sleep: %ld\n", program->time_to_sleep); 
}

int	ft_parse_input(t_program *program, char **av)
{
	if (ft_check_args(av) != 0)
	{
		program->philo_nbr = ft_atol(av[1]);
		program->time_to_die = ft_atol(av[2]);
		program->time_to_eat = ft_atol(av[3]); 
		program->time_to_sleep = ft_atol(av[4]); 
		if (program->time_to_die < 60 || program->time_to_sleep < 60
			|| program->time_to_eat < 60)
			ft_error_exit("Use timestamps superior than 60ms");
		if (av[(5)])
			program->nb_limit_meals = ft_atol(av[(5)]);
		else
			program->nb_limit_meals = -1;
	}
	else
		ft_error_exit("Some arguments were incorrect, please check everything");
		return (1); 
	return (0); 
}
