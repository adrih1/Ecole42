/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:57:51 by ahors             #+#    #+#             */
/*   Updated: 2024/02/15 17:39:06 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

void	handler(void)
{
	write(STDOUT_FILENO, "Hello\n", 6);
}

int	main(void)
{
	// signal(SIGINT, handler);
	while(1)
	{
		ft_printf("L'ID du client est: %d\n", getpid());
		sleep(1);	
	}
	return(0);
}