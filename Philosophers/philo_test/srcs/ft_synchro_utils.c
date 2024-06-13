#include "../header/philo.h"

//Spinlock until all threads are ready
void	ft_wait_all_threads(t_program *program)
{
	while (!ft_get_bool(&program->program_mtx, &program->all_threads_ready))
		;
}

// Monitor waits until all threads are not running
bool   ft_all_threads_are_running(t_mtx *mutex, long *threads, long philo_nbr)
{
	bool ret; 

	ret = false; 
	ft_safe_mutex_handle(mutex, LOCK); 
	if (*threads == philo_nbr)
		ret = true; 
	ft_safe_mutex_handle(mutex, UNLOCK); 
	return (ret); 
}

// Increase number of threads running to synchro with monitor
void	ft_increase_long(t_mtx *mutex, long *value)
{
	ft_safe_mutex_handle(mutex, LOCK); 
	(*value)++; 
	ft_safe_mutex_handle(mutex, UNLOCK); 
}


void	ft_desynchronize_philos(t_philosopher *philo)
{
	if ((philo->program->philo_nbr % 2) == 0)
	{
		if(philo->id % 2 == 0)
			ft_precise_usleep(3e4, philo->program); 
	}
	else
	{
		if(philo->id % 2)
			ft_thinking(philo, true); 
	}
}