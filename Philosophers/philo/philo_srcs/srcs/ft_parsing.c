/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:09:03 by ahors             #+#    #+#             */
/*   Updated: 2024/08/26 16:57:47 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

// Fonction d'affichage
// void	ft_printf_args(t_program *program)
// {
// 	printf("Philo Nbr: %ld\n", program->philo_nbr);
// 	printf("Time to die: %ld\n", program->time_to_die); 
// 	printf("Time to eat: %ld\n", program->time_to_eat); 
// 	printf("Time to sleep: %ld\n", program->time_to_sleep); 
// }

void	ft_parse_input(t_program *program, char **av)
{
	if (ft_check_args(av))
	{
		program->philo_nbr = ft_atol(av[1]);
		program->time_to_die = ft_atol(av[2]) * 1e3;
		program->time_to_eat = ft_atol(av[3]) * 1e3;
		program->time_to_sleep = ft_atol(av[4]) * 1e3;
		if (program->time_to_die < 6e4 || program->time_to_sleep < 6e4
			|| program->time_to_eat < 6e4)
			ft_error_exit("Use timestamps superior than 60ms");
		if (av[(5)])
			program->nb_limit_meals = ft_atol(av[(5)]);
		else
			program->nb_limit_meals = -1;
	}
	else
		ft_error_exit("Some arguments were incorrect, please check everything");
	// ft_printf_args(program);
}
