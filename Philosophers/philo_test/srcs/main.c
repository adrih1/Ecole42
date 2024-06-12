/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:01:47 by ahors             #+#    #+#             */
/*   Updated: 2024/06/12 10:22:25 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	main(int ac, char **av)
{
	t_program	program;

	if (ac != 5 && ac != 6)
		ft_error_exit("Wrong Input.\nInputs should be: number_of_philosophers time_to_die time_to_eat time_to_sleep number_of_times_each_philosopher_must_eat");
	else
	{
		// Parse Input --> Error checks and Filling program
		ft_parse_input(&program, av);
		// Data Init
		ft_data_init(&program);
		// Simu Start
		ft_simulation_start(&program);
		// Clean --> Philos are all full || A philo is dead
		ft_clean_program(&program);
	}
	return (0);
}
