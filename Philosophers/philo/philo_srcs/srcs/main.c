/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:01:47 by ahors             #+#    #+#             */
/*   Updated: 2024/06/14 14:12:57 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	main(int ac, char **av)
{
	t_program	program;

	if (ac != 5 && ac != 6)
		ft_error_exit("Wrong Input.\nInputs should be:"
			"nb_philosophers t_to_die t_to_eat t_to_sleep nb_meals");
	else
	{
		ft_parse_input(&program, av);
		ft_data_init(&program);
		ft_simulation_start(&program);
		ft_clean_program(&program);
	}
	return (0);
}
