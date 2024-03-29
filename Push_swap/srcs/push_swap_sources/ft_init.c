/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:18:16 by ahors             #+#    #+#             */
/*   Updated: 2024/02/13 15:17:30 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

// Init Stack
void	ft_init_stack(t_stack_node **a, char **argv)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (ft_error_syntax(argv[i]))
			ft_free_errors(a);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_free_errors(a);
		if (ft_error_duplicate(*a, (int)nbr))
			ft_free_errors(a);
		ft_append_node(a, (int)nbr);
		i++;
	}
}

// Append Nodes to Stack
void	ft_append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

// Init Nodes A
void	ft_init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	ft_current_index(a);
	ft_current_index(b);
	ft_set_target_a(a, b);
	ft_cost_analysis(a, b);
	ft_set_cheapest(a);
}

// Init Nodes B
void	ft_init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	ft_current_index(a);
	ft_current_index(b);
	ft_set_target_b(a, b);
}
