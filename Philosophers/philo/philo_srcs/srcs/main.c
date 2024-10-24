/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:01:47 by ahors             #+#    #+#             */
/*   Updated: 2024/10/24 10:47:39 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	main(int ac, char **av)
{
	t_program	program;
	pthread_t	monitor;

	if (ac != 5 && ac != 6)
		ft_error_exit("Wrong Input.\nInputs should be:"
						"nb_philosophers t_to_die t_to_eat t_to_sleep nb_meals");
	else
	{
		if (ft_parse_input(&program, av) != 0)
		{
			ft_error_exit("There was an issue while parsing data");
			return (1);
		}
		if (ft_data_init(&program) != 0)
		{
			ft_error_exit("There was an issue while initializing data");
			return (1);
		}
		if (program.philo_nbr != 1)
		{
			pthread_create(&monitor, NULL, (void *)ft_monitor, &program);
			pthread_join(monitor, NULL);
		}
		ft_clean_program(&program);
	}
	return (0);
}
