#include "../header/philo.h"

// OLD
void ft_philo_init_old(t_philosopher *philosopher, int i)
{
    philosopher->id = i;
    philosopher->meals_eaten = 0;
    philosopher->full = false;
}

void    ft_data_init_old(t_program *program)
{
    int i;

    i = 0;
    
    program->philos = ft_safe_malloc(program->philo_nbr * sizeof(t_philosopher));
    while (i < program->philo_nbr) 
    {
        ft_philo_init_old(&program->philos[i], i);
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




//NEW
// Si philo impair --> first fork is the left 
// Si philo pair --> first fork is the right
void    ft_assign_forks(t_philosopher *philo, t_fork *forks, int philo_position)
{
    int philo_nbr; 

    philo_nbr = philo->program->philo_nbr; 
    philo->first_fork = &forks[(philo_position + 1) % philo_nbr]; 
    philo->second_fork = &forks[philo_position];
    if (philo->id % 2 == 0)
    {
        philo->first_fork = &forks[philo_position]; 
        philo->second_fork = &forks[(philo_position + 1) % philo_nbr]; 
    }
}

void ft_philo_init(t_program *program)
{
    int i; 
    t_philosopher *philo;

    i = -1;
    while (++i < program->philo_nbr)
    {
        philo = program->philos + i; 
        philo->id = i + 1; 
        philo->meals_eaten = 0; 
        philo->program = program; 
         
        ft_assign_forks(philo, program->philos, i);
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
        ft_safe_mutex_handle(&program->forks[i].fork, INIT);
        program->forks[i].fork_id = i; 
        i++;
    }
    ft_philo_init(program);
}
    