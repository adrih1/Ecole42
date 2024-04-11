#include "../header/philo.h"


void ft_philo_init(t_philosopher *philosopher, int i)
{
    philosopher->id = i;
    philosopher->meals_eaten = 0;
    philosopher->full = false;
}

void ft_fork_init(t_fork *fork, t_program *program, int i)
{
    fork->fork_id = i;
    program->philos[i].l_fork = &program->forks[i];
    program->philos[i].r_fork = &program->forks[(i + 1) % program->philo_nbr];
    pthread_mutex_init(&program->philos[i].l_fork->fork, NULL);
    pthread_mutex_init(&program->philos[i].r_fork->fork, NULL);

}

// OLD
void    ft_data_init_old(t_program *program)
{
    int i;

    i = 0;
    
    program->philos = ft_safe_malloc(program->philo_nbr * sizeof(t_philosopher));
    while (i < program->philo_nbr) 
    {
        ft_philo_init(&program->philos[i], i);
        i++;
    }
    i = 0;
    program->forks = ft_safe_malloc(program->philo_nbr * sizeof(t_fork));
    while (i < program->philo_nbr) 
    {
        ft_fork_init(&program->forks[i], program, i);
        i++;
    }
}


void    ft_data_init(t_program *program)
{
    int i;

    program->end_simulation = false;
    program->philos = ft_safe_malloc(sizeof(t_philosopher) * program->philo_nbr);
    program->forks = ft_safe_malloc(sizeof(t_fork) * program->philo_nbr);
    i = 0;
    while (i < program->philo_nbr) 
    {
        ft_philo_init(&program->philos[i], i);
        i++;
    }
}
    