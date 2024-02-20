/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:57:46 by ahors             #+#    #+#             */
/*   Updated: 2024/02/20 17:01:35 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

void	ft_send_signal(int pid, char *str)
{
	int	i;
	int	bit;

	i = 0;
	while (str[i])
	{
		bit = 0;
		while (bit < 8)
		{
			if ((str[i] & (0x01 << bit)) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			bit++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = atoi(av[1]);
		ft_send_signal(pid, av[2]);
	}
	else
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./client <PID> <MESSAGE>\033[0m\n");
		return (1);
	}
	ft_send_signal(pid, "\n");
	return (0);
}
