#include "../header/philo.h"

void	ft_free_double_array(char **argv)
{
	int	i;
	int	len;

	i = 0;
	len = ft_length_of_char_array(argv);
	printf("len of argv: %d\n", len);
	while (i < len)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	ft_free_philosopher(t_philosopher *philosopher)
{
	if (philosopher != NULL)
	{
		pthread_mutex_destroy(&philosopher->philo_mutex);
		free(philosopher);
	}
}

// Free the program structure
void	ft_free_program(t_program *program)
{
	if (program != NULL)
	{
		if (program->philos != NULL)
		{
			for (int i = 0; i < program->philo_nbr; i++)
			{
				free_philosopher(&program->philos[i]);
			}
			free(program->philos);
		}
		if (program->forks != NULL)
		{
			free(program->forks);
		}
		pthread_mutex_destroy(&program->program_mtx);
		pthread_mutex_destroy(&program->write_mutex);
		free(program);
	}
}