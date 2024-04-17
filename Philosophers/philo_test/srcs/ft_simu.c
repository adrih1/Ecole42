#include "../header/philo.h"

// Eat Routine
// 1) Grab the forks : here first & second fork 
// 2) Eat : write eating, update last meal, uodate meals counter and usleep the amount of time and eventually bool full 
// Release the forks 

void    ft_eat(t_philosopher *philo)
{
    ft_safe_mutex_handle(&philo->first_fork->fork, LOCK);
    ft_write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
    ft_safe_mutex_handle(&philo->second_fork->fork, LOCK);
    ft_write_status(TAKE_SECOND_FORK, philo, DEBUG_MODE);

    ft_set_long(&philo->philo_mutex, &philo->last_meal_time, ft_get_time(MILISECOND));
    philo->meals_eaten++;
    ft_write_status(EATING, philo, DEBUG_MODE);
    ft_precise_usleep(philo->program->time_to_eat, philo->program);
    if(philo->program->nb_limit_meals > 0 && (philo->meals_eaten == philo->program->nb_limit_meals))
        ft_set_bool(&philo->philo_mutex, &philo->full, true);
    ft_safe_mutex_handle(&philo->first_fork->fork, UNLOCK);
    ft_safe_mutex_handle(&philo->second_fork->fork, UNLOCK);
}


void    *ft_simulation(void *data)
{
    t_philosopher *philo; 

    philo = (t_philosopher *)data; 
    //Spinlock
    ft_wait_all_threads(philo->program);

    //Set last meal time
    while (!ft_simulation_finished(philo->program))
    {
        if (philo->full)
            break; 
        //Eat 
        ft_eat(philo);

        //Sleep
        ft_write_status(SLEEPING, philo, DEBUG_MODE);
        ft_precise_usleep(philo->program->time_to_sleep, philo->program);        

        //Think
   
    }
    return (NULL);
}

void    ft_simulation_start(t_program *program)
{
    int i; 

    i = 0; 
    if (program->nb_limit_meals == 0)
        return; 
    else if (program->philo_nbr == 1)
        ; // TODO
    else
        while (i < program ->philo_nbr)
            ft_safe_thread_handle(&program->philos[i].thread_id, ft_simulation, &program->philos[i], CREATE);
   
    //Start of Simulation 
    program->start_simulation = ft_get_time(MILISECOND);

    //Threads are ready but we need a mutex to prevent from race conditions when setting the boolean
    ft_set_bool(&program->program_mtx, &program->all_threads_ready, true);

    //Wait for everyone
    i = -1; 
    while (++i < program->philo_nbr)
        ft_safe_thread_handle(&program->philos[i].thread_id, NULL, NULL, JOIN);

    //Si on arrive ici les philos sont full

    
    free(program->philos);
    free(program->forks);
}