/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:01:47 by ahors             #+#    #+#             */
/*   Updated: 2024/02/23 15:42:58 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int main(int ac, char **av)
{
    if(ac == 5 || ac == 6)
    {
	    ft_printf("\033[90mProcessing...\033[0m\n");
        sleep(1);
        if(ft_check_args(av))
	        ft_printf("Correct\n");
        else
	      ft_printf("\033[91mError: Use only digits.\033[0m\n");       
    }
    else 
        ft_printf("\033[91mError: wrong format.\033[0m\n");       
    return (0);
}
