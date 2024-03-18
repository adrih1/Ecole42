#include "../header/philo.h"


long    meals_eaten = 0; 
pthread_mutex_t mutex; 

void *philosopher_thread(void *arg) {
    t_philosopher *philosopher = (t_philosopher *)arg;
    printf("Philosopher %d is thinking\n", philosopher->id);
    pthread_mutex_lock(&mutex);
    meals_eaten++;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void    ft_data_init(t_program *program)
{
    int i ;

    i = 0;
    program->philos = ft_safe_malloc(program->philo_nbr);
    pthread_t threads[program->philo_nbr];
    while (i < program->philo_nbr) 
    {
        program->philos[i].id = i;
        if (pthread_create(&threads[i], NULL, philosopher_thread, (void *)&program->philos[i]) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
        i++;
    }
    i = 0;
    while (i < program->philo_nbr) 
    {
        if (pthread_join(threads[i], NULL) != 0) 
        {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
        i++;
    }
    pthread_mutex_destroy(&mutex);
    printf("Meals Eaten %ld\n", meals_eaten);
}
    