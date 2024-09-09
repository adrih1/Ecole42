/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:58:14 by ahors             #+#    #+#             */
/*   Updated: 2024/09/09 10:40:49 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
/*
---------------------------------------------------------------------------------
|                                    LIBRAIRIE                                  |
---------------------------------------------------------------------------------
*/

# include <errno.h>
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>  // Printf
# include <stdlib.h> //malloc, free
# include <sys/time.h>
# include <unistd.h> // write, sleep

# define RED "\033[91m"
# define GREEN "\033[92m"
# define YELLOW "\033[93m"
# define PURPLE "\033[94m"
# define WHITE "\033[97m"
# define RESET "\033[0m"

# ifndef PHILO_MAX
#  define PHILO_MAX 200
# endif

# ifndef DEBUG_MODE
#  define DEBUG_MODE 0
# endif

/*
---------------------------------------------------------------------------------
|                                    CODES                                  |
---------------------------------------------------------------------------------
*/

// MUTEX AND THREADS
typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}							t_opcode;

// TIME CODE
typedef enum e_time_code
{
	SECOND,
	MILISECOND,
	MICROSECOND,
}							t_time_code;

// PHILO STATUS
typedef enum e_philo_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}							t_philo_status;

/*
------------------------------------------------
|                 STRUCTURES                   |
------------------------------------------------
*/

typedef pthread_mutex_t		t_mtx;
typedef struct s_program	t_program;

typedef struct s_fork
{
	t_mtx					fork;
	int						fork_id;
}							t_fork;

typedef struct s_philosopher
{
	int						id;
	long					meals_eaten;
	bool					is_full;
	long					last_meal_time;
	t_fork					*first_fork;
	t_fork					*second_fork;
	pthread_t				thread_id;
	t_mtx					philo_mutex;
	t_program				*program;
}							t_philosopher;

typedef struct s_program
{
	long					philo_nbr;
	long					time_to_die;
	long					time_to_eat;
	long					time_to_sleep;
	long					nb_limit_meals;
	long					start_simulation;
	long					philos_full;
	bool					is_dead;
	pthread_t				monitor;
	t_mtx					write_mutex;
	t_mtx					dead_mutex;
	t_fork					*forks;
	t_philosopher			*philos;
}							t_program;

/*
--------------------------------------------------------------------------------
|                                    FONCTIONS                                  |
--------------------------------------------------------------------------------
*/

// Errors Checks
int							ft_is_digit(char *str);
int							ft_is_valid_arg(char *arg);
int							ft_is_valid_nb_meals(char **av, int index);
int							ft_is_valid_range(char **av, int len);
int							ft_is_valid_timestamp(char **av);
int							ft_check_args(char **av);

// Parsing
int							ft_parse_input(t_program *program, char **av);

// Init
int							ft_data_init(t_program *program);

// Simulation
void						*ft_dinner(void *arg);
void						ft_monitor(t_program *program);

// Utils
long						ft_atol(const char *str);
int							ft_length_of_char_array(char **av);
long						ft_get_current_time_in_ms(void);
int							ft_check_philo_is_full(t_philosopher *philo);
int							ft_check_philo_is_dead(t_philosopher *philo);
void						ft_usleep(long time_in_ms);

// Clean
void						ft_clean_program(t_program *program);

// Display
int							ft_error_exit(const char *error);
void						ft_write_status(t_philosopher *philo,
								const char *status);

#endif