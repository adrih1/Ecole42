/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:25:58 by ahors             #+#    #+#             */
/*   Updated: 2024/01/17 10:05:45 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include <stdio.h>

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
	// bool			split_used;

	a = NULL;
	b = NULL;
	// split_used = false; 
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		// split_used = true; 
	}
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
	// if (split_used)
	// 	ft_free_argv(argv);
	ft_free_stack(&a);
	return (0);
}
