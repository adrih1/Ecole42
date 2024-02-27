#include "../header/philo.h"

void    ft_parse_input(t_program *program, char **av)
{
    if(ft_check_args(av))
    {
        program->philo_nbr = ft_atol(av[1]); 
        program->time_to_die = ft_atol(av[2]);
        program->time_to_eat = ft_atol(av[3]);
        program->time_to_sleep = ft_atol(av[4]);
        if(av[(5)])
            program->nb_limit_meals = ft_atol(av[(5)]);
        else 
            program->nb_limit_meals = -1;
    }
}