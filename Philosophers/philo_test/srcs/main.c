/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:01:47 by ahors             #+#    #+#             */
/*   Updated: 2024/02/27 15:29:42 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int main(int ac, char **av)
{
    t_program		program;

    if(ac != 5 && ac != 6)
        printf(RED "Error: Not the valid nummber of arguments.\n" RESET);
    else
    {
        //Parse Input --> Error checks and Filling program
        ft_parse_input(&program, av);
        //Data Init
        // ft_data_init(&program);
        // //Simu Start
        // ft_simu_start(&program);
        // //Clean --> Philos are all full || A philo is dead 
        // ft_clean_program(&program);     
    }
    return (0);
}
