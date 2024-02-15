/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:57:51 by ahors             #+#    #+#             */
/*   Updated: 2024/02/15 18:46:45 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

void	handler(int num)
{
	write(STDOUT_FILENO, "Hello\n", 6);
}

void	handler_sigusr1(int num)
{
	write(STDOUT_FILENO, "Sig User 1\n", 6);
}

void	handler_sigusr2(int num)
{
	write(STDOUT_FILENO, "Sig User 2\n", 6);
}

int	main(void)
{
	signal(SIGUSR1, handler_sigusr1);
	signal(SIGUSR2, handler_sigusr2);
	while(1)
	{
		ft_printf("L'ID du client est: %d\n", getpid());
		sleep(1);	
	}
	return(0);
}
