/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:49:52 by adrienhors        #+#    #+#             */
/*   Updated: 2024/04/10 12:19:35 by adrienhors       ###   ########.fr       */
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

void print_timestamp(long timestamp_ms) {
    time_t timestamp_sec = timestamp_ms / 1000; // Convertir le timestamp en secondes
    struct tm *local_time = localtime(&timestamp_sec);

    // Convertir chaque composante de temps en format de chaîne
    char time_str[100];
    snprintf(time_str, sizeof(time_str), "%04d-%02d-%02d %02d:%02d:%02d",
             local_time->tm_year + 1900, local_time->tm_mon + 1, local_time->tm_mday,
             local_time->tm_hour, local_time->tm_min, local_time->tm_sec);
    
    printf("La simulation a commencée le: %s\n", time_str);
}

long get_current_timestamp() 
{
	long timestamp_ms;
    struct timeval current_time;
    
	gettimeofday(&current_time, NULL);
	timestamp_ms = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return(timestamp_ms);
}
