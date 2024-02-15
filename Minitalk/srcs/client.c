/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:57:46 by ahors             #+#    #+#             */
/*   Updated: 2024/02/15 18:48:01 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

void	ft_send_sginal(int pid, char *str)
{
	int	i;
    int j;
    int bit;

	i = 0;
    printf("PID: %d\n", pid);
	while (str[i])
	{
        j = 7;
        while (j >= 0)
        {
            bit = (str[i] >> j) & 1;
            if(bit == 1)
                kill(pid, 30);
            else if (bit == 0)
                kill(pid, 31);
            printf("%d", bit);
            j--;
        }
		i++;
    }
    usleep(4200);

}


int	main(int ac, char **av)
{
    int pid;

    pid = atoi(av[1]);
    if (ac == 3)
	    ft_send_sginal(pid, av[2]);
    else
        printf("No string provided\n");
    return (0);
}
