/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:58:14 by ahors             #+#    #+#             */
/*   Updated: 2024/04/22 15:01:08 by ahors            ###   ########.fr       */
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

# define PHILO_MAX 200
# define DEBUG_MODE 0 // Write function macro
# define RED "\033[91m"
# define GREEN "\033[92m"
# define YELLOW "\033[93m"
# define PURPLE "\033[94m"
# define WHITE "\033[97m"
# define RESET "\033[0m"

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
---------------------------------------------------------------------------------
|                                    STRUCTURES                                  |
---------------------------------------------------------------------------------
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
	bool					full;
	long					last_meal_time;
	t_fork					*first_fork;
	t_fork					*second_fork;
	pthread_t				thread_id;
	t_mtx philo_mutex;
		// Useful to avoid race conditions with the monitor when updating the lasts_meal_time
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
	bool					end_simulation;
	bool					all_threads_ready;
	long					nbr_threads_running;
	pthread_t				monitor;
	t_mtx					program_mtx;
	t_mtx					write_mutex;
	t_fork					*forks;
	t_philosopher			*philos;
}							t_program;

/*
---------------------------------------------------------------------------------
|                                    FONCTIONS                                  |
---------------------------------------------------------------------------------
*/

// Errors Checks
int							ft_is_digit(char *str);
int							ft_is_valid_arg(char *arg);
int							ft_is_valid_nb_meals(char **av, int index);
int							ft_is_valid_range(char **av, int len);
int							ft_check_args(char **av);

// Parsing
void						ft_parse_input(t_program *program, char **av);

// Init
void						ft_data_init(t_program *program);

// Protect
void						*ft_safe_malloc(size_t bytes);
void						ft_mutex_error_handle(int status, t_opcode opcode);
void						ft_safe_mutex_handle(t_mtx *mutex, t_opcode opcode);
void						ft_thread_error_handle(int status, t_opcode opcode);
void						ft_safe_thread_handle(pthread_t *thread,
								void *(*foo)(void *), void *data,
								t_opcode opcode);

// Getters and Setters
void						ft_set_bool(t_mtx *mutex, bool *dest, bool value);
bool						ft_get_bool(t_mtx *mutex, bool *value);
void						ft_set_long(t_mtx *mutex, long *dest, long value);
bool						ft_get_long(t_mtx *mutex, long *value);
bool						ft_simulation_finished(t_program *program);

// Synchro Utils
void						ft_wait_all_threads(t_program *program);

// Simulation
void						*ft_simulation(void *data);
void						ft_simulation_start(t_program *program);

// Utils
long						ft_atol(const char *str);
int							ft_length_of_char_array(char **av);
long						ft_get_time(t_time_code time_code);
void						ft_precise_usleep(long usec, t_program *program);

// Clean
void						ft_free_double_array(char **argv);
void						ft_free_program(t_program *program);
void						ft_free_philosopher(t_philosopher *philosopher);

// Display
void						ft_error_exit(const char *error);
void						ft_write_status(t_philo_status status,
								t_philosopher *philo, bool debug);
void						ft_write_status_debug(t_philo_status status,
								t_philosopher *philo, long elapsed);

#endif