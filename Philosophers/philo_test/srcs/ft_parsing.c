#include "../header/philo.h"

void	ft_parse_input(t_program *program, char **av)
{
	if (ft_check_args(av))
	{
		program->philo_nbr = ft_atol(av[1]);
		program->time_to_die = ft_atol(av[2]) * 1e3;
		program->time_to_eat = ft_atol(av[3]) * 1e3;
		program->time_to_sleep = ft_atol(av[4]) * 1e3;
		if(program->time_to_die < 6e4 || program->time_to_eat < 6e4 || program->time_to_sleep < 6e4)
			ft_error_exit("Use timestamps superior than 60ms"); 
		if (av[(5)])
			program->nb_limit_meals = ft_atol(av[(5)]);
		else
			program->nb_limit_meals = -1;
	}
	else
		ft_error_exit("Some arguments were incorrect, please check everything");
}