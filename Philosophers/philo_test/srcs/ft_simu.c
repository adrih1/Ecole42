#include "../header/philo.h"

void *philosopher_thread(void *arg) {
    t_philosopher *philosopher = (t_philosopher *)arg;

    while (1) {
        if(!pthread_mutex_lock(&philosopher->l_fork->fork))
            printf("Philosopher %d has taken a fork\n", philosopher->id);
        if (pthread_mutex_trylock(&philosopher->r_fork->fork) == 0) 
        {
            printf("Philosopher %d has taken a fork\n", philosopher->id);
            break; // Si les deux fourchettes sont disponibles, sortir de la boucle
        } else {
            pthread_mutex_unlock(&philosopher->l_fork->fork); // Relâcher la fourchette gauche si la droite est prise
        }
    }

    // Manger
    philosopher->meals_eaten++;
    printf("Philosopher %d is eating\n", philosopher->id);

    // Libérer les fourchettes après avoir mangé
    pthread_mutex_unlock(&philosopher->l_fork->fork);
    pthread_mutex_unlock(&philosopher->r_fork->fork);
    return NULL;
}

void    ft_simu_start(t_program *program)
{
    int i;
    pthread_t threads[program->philo_nbr];

    program->start_simulation = get_current_timestamp();
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