#include "../header/push_swap.h"

void	ft_free_errors_checker(t_stack_node **a, t_stack_node **b, char *line)
{
	write(1, "Error\n", 6);
	free(line);
	ft_free_stack(a);
	ft_free_stack(b);
	exit(1);
}

char	*ft_sub_check(char *line, t_stack_node **a, t_stack_node **b)
{
	if (ft_strncmp(line, "sa\n", 3) == 0 && line[3] == '\0')
		sa(a, false);
	else if (ft_strncmp(line, "sb\n", 3) == 0 && line[3] == '\0')
		sb(b, false);
	else if (ft_strncmp(line, "ss\n", 3) == 0 && line[3] == '\0')
		ss(a, b, false);
	else if (ft_strncmp(line, "pa\n", 3) == 0 && line[3] == '\0')
		pa(a, b, false);
	else if (ft_strncmp(line, "pb\n", 3) == 0 && line[3] == '\0')
		pb(a, b, false);
	else if (ft_strncmp(line, "ra\n", 3) == 0 && line[3] == '\0')
		ra(a, false);
	else if (ft_strncmp(line, "rb\n", 3) == 0 && line[3] == '\0')
		rb(b, false);
	else if (ft_strncmp(line, "rr\n", 3) == 0 && line[3] == '\0')
		rr(a, b, false);
	else if (ft_strncmp(line, "rra\n", 4) == 0 && line[4] == '\0')
		rra(a, false);
	else if (ft_strncmp(line, "rrb\n", 4) == 0 && line[4] == '\0')
		rrb(b, false);
	else if (ft_strncmp(line, "rrr\n", 4) == 0 && line[4] == '\0')
		rrr(a, b, false);
	else
		ft_free_errors_checker(a, b, line);
	return (get_next_line(0));
}


void	ft_check(t_stack_node **a, t_stack_node **b, char *line)
{
	char	*tmp;

	while (line && line[0] != '\0')
	{
		printf("line = %s\n", line);
		tmp = line;
		line = ft_sub_check(line, a, b);
		free(tmp);
	}
	if (*b && !ft_stack_sorted(*a))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	free(line);
}


int	main(int argc, char **argv)
{
    t_stack_node	*a;
	t_stack_node	*b;
    char    *line;
	
	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	ft_init_stack(&a, argv + 1);
	b = NULL;
	line = get_next_line(0);
	if (!line && !ft_stack_sorted(a))
		write(1, "KO\n", 3);
	else if (!line && ft_stack_sorted(a))
		write(1, "OK\n", 3);
	else
		ft_check(&a, &b, line);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
