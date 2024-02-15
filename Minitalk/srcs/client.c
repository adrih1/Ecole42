/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:57:46 by ahors             #+#    #+#             */
/*   Updated: 2024/02/15 17:37:08 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

void	ft_chartobits(char c)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		printf("%d", bit);
		i--;
	}
	printf("\n");
}

void	ft_stringtobits(int pid, char *str)
{
	int	i;

	i = 0;
    printf("PID: %d\n", pid);
	while (str[i])
	{
        
		ft_chartobits(str[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
    if (ac == 2)
	    ft_stringtobits(0, av[1]);
    else
        printf("No string provided\n");

    return (0);
}
