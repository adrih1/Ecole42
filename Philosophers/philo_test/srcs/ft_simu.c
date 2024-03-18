#include "../header/philo.h"


void *philosopher_thread(void *arg) {
    t_philosopher *philosopher = (t_philosopher *)arg;

    // Manger
    philosopher->meals_eaten++;
    printf("Philosopher %d is eating\n", philosopher->id);

    return NULL;
}

void    ft_simu_start(t_program *program)
{
    int i;
    pthread_t threads[program->philo_nbr];

    program->start_simulation = get_current_timestamp();
    printf(GREEN "Simulation has started at: %ld\n" RESET, program->start_simulation); 
    i = 0;
    while (i < program->philo_nbr)
    {
        if (pthread_create(&threads[i], NULL, philosopher_thread, (void *)&program->philos[i]) != 0) 
            ft_error_exit("Error during thread creation");
        i++;
    }
    i = 0;
    while (i < program->philo_nbr) 
    {
        if (pthread_join(threads[i], NULL) != 0) 
            ft_error_exit("Error during thread joining");
        i++;
    }
    free(program->philos);
    free(program->forks);
}