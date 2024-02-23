/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:01:47 by ahors             #+#    #+#             */
/*   Updated: 2024/02/23 16:45:35 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int main(int ac, char **av)
{
    if(ac == 5 || ac == 6)
    {   
        if(ft_check_args(av))
	        printf("Correct\n");
        else
        {  
	        printf("\033[91mError: Use only digits amd melas should not exceed 200.\033[0m\n");       
            return (0);
        }
    }
    else 
        printf("\033[91mError: Not the valid nummber of arguments.\033[0m\n");       
    return (0);
}
