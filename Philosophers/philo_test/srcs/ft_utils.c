/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:49:52 by adrienhors        #+#    #+#             */
/*   Updated: 2024/02/27 16:59:13 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int ft_length_of_char_array(char **av) 
{
    int length = 0;
    
    while (av[length] != NULL) 
        length++;
    return length;
}

void	ft_free_double_array(char **argv)
{
	int i;
	int len;

	i = 0;
	len = ft_length_of_char_array(argv);
	printf("len of argv: %d\n", len);
	while(i < len)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	ft_error_exit(const char *error)
{
	printf(RED"🚨 %s 🚨\n"RESET, error);
	exit(EXIT_FAILURE);
}