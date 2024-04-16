#include "../header/philo.h"

void	ft_error_exit(const char *error)
{
	printf(RED"🚨 %s 🚨\n"RESET, error);
	exit(EXIT_FAILURE);
}

void    ft_write_status()


