#include "../header/philo.h"


//if no meals 
        // return
    //if only one philosopher 
        // ad hoc function
    //If valid 
        //Create threads, all philos 
        // Create a monitor thread --> Searching for philosophers dead
        // Synchronize the beginning of the simulation
        // JOIN everyone
 
void    *ft_simulation(void *data)
{
    t_philosopher *philo; 

    philo = (t_philosopher *)data; 
    //Spinlock
    ft_wait_all_threads(philo->program);

    //Set last meal time
    while (!ft_simulation_finished(philo->program))
    {
        if (philo->full) // Maybe not safe ?
            break; 
        //Eat 


        //Sleep
        

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