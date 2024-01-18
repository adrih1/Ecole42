/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:25:58 by ahors             #+#    #+#             */
/*   Updated: 2024/01/18 15:45:25 by ahors            ###   ########.fr       */
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
	{
		argv = ft_split(argv[1], ' ');
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
	print_stack_nodes(a);
	ft_free_stack(&a);
	return (0);
}
