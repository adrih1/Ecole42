#include "../header/philo.h"

void	*ft_monitor(void *data)
{
	t_program *program;

	program = (t_program *)data;

	while (!ft_all_threads_running())
	{
		;
	}
}