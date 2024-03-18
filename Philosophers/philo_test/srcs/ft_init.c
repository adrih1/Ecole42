#include "../header/philo.h"

long    meals_eaten = 0; 
pthread_mutex_t mutex; 

void *philosopher_thread(void *arg) {
    t_philosopher *philosopher = (t_philosopher *)arg;
    printf("Philosopher %d is thinking || Philosopher %d has eaten %ld meals || Last meal time %ld || ", philosopher->id, philosopher->id, philosopher->meals_eaten, philosopher->last_meal_time);
    if (philosopher->full == 0)
        printf("Philosopher %d is not full\n", philosopher->id);   
    // pthread_mutex_lock(&mutex);
    meals_eaten++;
    // pthread_mutex_unlock(&mutex);
    return NULL;
}

void ft_philo_init(t_philosopher *philosopher, int i)
{
    philosopher->id = i;
    philosopher->meals_eaten = 0;
    philosopher->full = false;
    // philosopher->last_meal_time = get_current_timestamp();
}

void    ft_data_init(t_program *program)
{
    int i ;

    i = 0;
    program->philos = ft_safe_malloc(program->philo_nbr);
    pthread_t threads[program->philo_nbr];
    while (i < program->philo_nbr) 
    {
        ft_philo_init(&program->philos[i], i);
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
    pthread_mutex_destroy(&mutex);
    printf("Meals Eaten %ld\n", meals_eaten);
}
    