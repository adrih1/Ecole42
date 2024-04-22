#include "../header/philo.h"

int	ft_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			printf(RED "Only use digits.\n" RESET);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_is_valid_arg(char *arg)
{
	if (ft_atol(arg) == 0)
	{
		printf(RED "No value should equal to 0.\n" RESET);
		return (0);
	}
	return (1);
}

int	ft_is_valid_nb_meals(char **av, int index)
{
	if (av[index] && ft_atol(av[index]) > 200)
	{
		printf(RED "The number of meals should not be superior to 200.\n" RESET);
		return (0);
	}
	return (1);
}

int	ft_is_valid_range(char **av, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (av[i] && (ft_atol(av[i]) > 2147483647))
		{
			printf(RED "The limit is int max (2147483647).\n" RESET);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_args(char **av)
{
	int len;
	int i;

	len = ft_length_of_char_array(av);
	i = 1;
	while (i < len)
	{
		if (!ft_is_digit(av[i]) || !ft_is_valid_arg(av[i]))
			return (0);
		i++;
	}
	if (!ft_is_valid_nb_meals(av, 5))
		return (0);
	if (!ft_is_valid_range(av, len))
		return (0);
	return (1);
}