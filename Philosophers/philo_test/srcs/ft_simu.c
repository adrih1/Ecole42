#include "../header/philo.h"

void	ft_thinking(t_philosopher *philo)
{
	ft_write_status(THINKING, philo, DEBUG_MODE);
}

void	*ft_lone_philo(void *data)
{
	t_philosopher *philo; 

	philo = (t_philosopher *)data; 
	ft_wait_all_threads(philo->program);
	ft_set_long(&philo->philo_mutex, &philo->last_meal_time, ft_get_time(MILISECOND)); 
	ft_increase_long(&philo->program->program_mtx, &philo->program->nbr_threads_running);
	ft_write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	while (!ft_simulation_finished(philo->program))
		usleep(200); 
	return (NULL);
}

void	ft_eat(t_philosopher *philo)
{
	ft_safe_mutex_handle(&philo->first_fork->fork, LOCK); 
	ft_write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	ft_safe_mutex_handle(&philo->second_fork->fork, LOCK);
	ft_write_status(TAKE_SECOND_FORK, philo, DEBUG_MODE);
	ft_set_long(&philo->philo_mutex, &philo->last_meal_time, ft_get_time(MILISECOND));
	philo->meals_eaten++;
	ft_write_status(EATING, philo, DEBUG_MODE);
	ft_precise_usleep(philo->program->time_to_eat, philo->program);
	if (philo->program->nb_limit_meals > 0
		&& (philo->meals_eaten == philo->program->nb_limit_meals))
		ft_set_bool(&philo->philo_mutex, &philo->full, true);
	ft_safe_mutex_handle(&philo->first_fork->fork, UNLOCK);
	ft_safe_mutex_handle(&philo->second_fork->fork, UNLOCK);
}

void	*ft_simulation(void *data)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)data;
	// Spinlock
	ft_wait_all_threads(philo->program);

	ft_set_long(&philo->philo_mutex, &philo->last_meal_time, ft_get_time(MILISECOND)); 

	// Synchro with Monitor
	ft_increase_long(&philo->program->program_mtx, &philo->program->nbr_threads_running);


	// Set last meal time
	while (!ft_simulation_finished(philo->program))
	{
		if (philo->full)
			break ;
		// Eat
		ft_eat(philo);
		// Sleep
		ft_write_status(SLEEPING, philo, DEBUG_MODE);
		ft_precise_usleep(philo->program->time_to_sleep, philo->program);
		// Think
		ft_thinking(philo);
	}
	return (NULL);
}

void	ft_simulation_start(t_program *program)
{
	int i;

	i = -1; 
	if (program->nb_limit_meals == 0)
		return ;
	else if (program->philo_nbr == 1)
		ft_safe_thread_handle(&program->philos[0].thread_id, ft_lone_philo, &program->philos[0], CREATE);
	else
		while (++i < program->philo_nbr)
			ft_safe_thread_handle(&program->philos[i].thread_id, ft_simulation,
				&program->philos[i], CREATE);

	// Monitor
	ft_safe_thread_handle(&program->monitor, ft_monitor_simulation, program, CREATE);

	// Start of Simulation
	program->start_simulation = ft_get_time(MILISECOND);

	// Threads are ready but we need a mutex to prevent from race conditions when setting the boolean
	ft_set_bool(&program->program_mtx, &program->all_threads_ready, true);

	// Wait for everyone
	i = -1;
	while (++i < program->philo_nbr)
		ft_safe_thread_handle(&program->philos[i].thread_id, NULL, NULL, JOIN);

	// Si on arrive ici les philos sont full
	ft_set_bool(&program->program_mtx, &program->end_simulation, true);
	ft_safe_thread_handle(&program->monitor, NULL, NULL, JOIN);
}
