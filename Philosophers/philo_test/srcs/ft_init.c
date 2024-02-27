#include "../header/philo.h"


void    ft_data_init(t_program *program)
{
    program->end_simulation = false; 
    program->philos = ft_safe_malloc(program->philo_nbr);

}