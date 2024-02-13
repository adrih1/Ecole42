#include "../header/push_swap.h"

void	ft_free_errors_checker(t_stack_node **a, t_stack_node **b, char *line)
{
	write(2, "Error\n", 6);
	free(line);
	ft_free_stack(a);
	ft_free_stack(b);
	exit(1);
}


static void	ft_print_stack_nodes(t_stack_node *head)
{
	t_stack_node	*current;

	current = head;
	while (current != NULL)
	{
		printf("%d\n", current->nbr);
		current = current->next;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}



void	ft_sub_check(char *line, t_stack_node **a, t_stack_node **b)
{
	if (ft_strcmp(line, "sa\n") == 0 && line[3] == '\0')
		sa(a, false);
	else if (ft_strcmp(line, "sb\n") == 0 && line[3] == '\0')
		sb(b, false);
	else if (ft_strcmp(line, "ss\n") == 0 && line[3] == '\0')
		ss(a, b, false);
	else if (ft_strcmp(line, "pa\n") == 0 && line[3] == '\0')
		pa(a, b, false);
	else if (ft_strcmp(line, "pb\n") == 0 && line[3] == '\0')
		pb(b, a, false);
	else if (ft_strcmp(line, "ra\n") == 0 && line[3] == '\0')
		ra(a, false);
	else if (ft_strcmp(line, "rb\n") == 0 && line[3] == '\0')
		rb(b, false);
	else if (ft_strcmp(line, "rr\n") == 0 && line[3] == '\0')
		rr(a, b, false);
	else if (ft_strcmp(line, "rra\n") == 0 && line[4] == '\0')
		rra(a, false);
	else if (ft_strcmp(line, "rrb\n") == 0 && line[4] == '\0')
		rrb(b, false);
	else if (ft_strcmp(line, "rrr\n") == 0 && line[4] == '\0')
		rrr(a, b, false);
	else
		ft_free_errors_checker(a, b, line);
}


void	ft_check(t_stack_node **a, t_stack_node **b, char *line)
{
	while (line)
	{
		ft_sub_check(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	if (ft_stack_sorted(*a) && *b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
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
	line = get_next_line(0);
	if (!line && !ft_stack_sorted(a))
		write(1, "KO\n", 3);
	else if (!line && ft_stack_sorted(a))
		write(1, "OK\n", 3);
	else
		ft_check(&a, &b, line);
	ft_print_stack_nodes(a);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
