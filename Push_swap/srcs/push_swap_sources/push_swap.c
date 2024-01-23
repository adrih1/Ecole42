/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:25:58 by ahors             #+#    #+#             */
/*   Updated: 2024/01/23 11:58:22 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"


void	print_stack_nodes(t_stack_node *head)
{
	t_stack_node	*current;

	current = head;
	while (current != NULL)
	{
		printf("%d\n", current->nbr);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	
	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	ft_init_stack(&a, argv + 1);
	if (!ft_stack_sorted(a))
	{
		if (ft_stack_len(a) == 2)
			sa(&a, false);
		else if (ft_stack_len(a) == 3)
			ft_sort_three(&a);
		else
			ft_sort_stacks(&a, &b);
	}
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}


// MAIN FOR CHECKER
// int	main(int argc, char **argv)
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;
// 	char	*line;

// 	stack_a = NULL;
// 	stack_b = NULL;

// 	ft_arg_to_stack(&stack_a, argv, argc == 2);
// 	stack_b = NULL;
// 	line = get_next_line(0);
// 	if (!line && !is_sorted_stack(&stack_a))
// 		write(1, "KO\n", 3);
// 	else if (!line && is_sorted_stack(&stack_a))
// 		write(1, "OK\n", 3);
// 	else
// 		ft_check(&stack_a, &stack_b, line);
// 	free_stack(&stack_a);
// 	free_stack(&stack_b);
// 	return (0);
// }