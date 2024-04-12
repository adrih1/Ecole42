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
 
void     ft_wait_all_threads()
{

}

void    *ft_simulation(void *data)
{
    t_philosopher *philo; 

    philo = (t_philosopher *)data; 
    ft_wait_all_threads(philo->program);

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
    {
        while (i < program ->philo_nbr)
            ft_safe_thread_handle(&program->philos[i].thread_id, ft_simulation, &program->philos[i], CREATE);
    }

    
    free(program->philos);
    free(program->forks);
}