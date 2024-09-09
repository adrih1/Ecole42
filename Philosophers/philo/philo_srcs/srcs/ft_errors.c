/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:03:30 by ahors             #+#    #+#             */
/*   Updated: 2024/09/09 10:42:00 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			printf(RED "Only use digits.\n" RESET);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_is_valid_arg(char *arg)
{
	if (ft_atol(arg) == 0)
	{
		printf(RED "No value should equal to 0.\n" RESET);
		return (0);
	}
	return (1);
}

int	ft_is_valid_nb_meals(char **av, int index)
{
	if (av[index] && ft_atol(av[index]) > 200)
	{
		printf(RED "The number of meals should not be superior to 200.\n" RESET);
		return (0);
	}
	return (1);
}

int	ft_is_valid_range(char **av, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (av[i] && (ft_atol(av[i]) > 2147483647))
		{
			printf(RED "The limit is int max (2147483647).\n" RESET);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_is_valid_timestamp(char **av)
{
	if (ft_atol(av[2]) < 60 || ft_atol(av[3]) < 60 || ft_atol(av[4]) < 60)
	{
		ft_error_exit("Use timestamps superior than 60ms");
		return (1);
	}
	return (0);
}
