/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:58:14 by ahors             #+#    #+#             */
/*   Updated: 2024/04/10 15:32:53 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
/*
---------------------------------------------------------------------------------
|                                    LIBRAIRIE                                  |
---------------------------------------------------------------------------------
*/

# include <stdio.h> // Printf
# include <stdlib.h> //malloc, free
# include <unistd.h> // write, sleep
# include <stddef.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
#include <errno.h>

# define PHILO_MAX 200
# define RED     "\033[91m"
# define GREEN   "\033[92m"
# define YELLOW  "\033[93m"
# define PURPLE  "\033[94m"
# define WHITE   "\033[97m"
# define RESET   "\033[0m"


/*
---------------------------------------------------------------------------------
|                                    CODES                                  |
---------------------------------------------------------------------------------
*/

typedef enum e_opcode
{
	LOCK, 
	UNLOCK, 
	INIT, 
	DESTROY, 
	CREATE, 
	JOIN,
	DETACH,
}	t_opcode;


/*
---------------------------------------------------------------------------------
|                                    STRUCTURES                                  |
---------------------------------------------------------------------------------
*/

typedef pthread_mutex_t t_mtx;
typedef struct s_program t_program;

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
} t_fork;


typedef struct s_philosopher
{
	int				id;
	long			meals_eaten;
	bool			full;
	long			last_meal_time;
	t_fork			*l_fork;
	t_fork			*r_fork;
	pthread_t		*thread_id;
	t_program		*program;
}					t_philosopher;


typedef struct s_program
{
	long	philo_nbr; 
	long	time_to_die; 
	long	time_to_eat; 
	long	time_to_sleep; 
	long	nb_limit_meals; 
	long	start_simulation; 
	bool		end_simulation; 
	t_fork 			*forks; 
	t_philosopher	*philos;
}					t_program;


/*
---------------------------------------------------------------------------------
|                                    FONCTIONS                                  |
---------------------------------------------------------------------------------
*/

// Errors Checks
int ft_is_digit(char *str);
int ft_is_valid_arg(char *arg); 
int ft_is_valid_nb_meals(char **av, int index);
int ft_is_valid_range(char **av, int len);
int ft_check_args(char **av);

//Parsing
void    ft_parse_input(t_program *program, char **av);

//Init 
void    ft_data_init(t_program *program);

//Simu Start
void 	ft_simu_start(t_program *program);

// Protect
void	*ft_safe_malloc(size_t bytes);
void	ft_safe_mutex_handle(t_mtx *mutex, t_opcode opcode);


// Utils
long	ft_atol(const char *str);
int ft_length_of_char_array(char **av);
long get_current_timestamp();



// Display
void	ft_error_exit(const char *error);


#endif