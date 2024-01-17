/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:19:53 by ahors             #+#    #+#             */
/*   Updated: 2024/01/17 10:39:46 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = ft_get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		ft_rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		ft_rev_rotate_both(a, b, cheapest_node);
	ft_prep_for_push(a, cheapest_node, 'a');
	ft_prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}

void	ft_move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	ft_prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

void	ft_min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != ft_find_min(*a)->nbr)
	{
		if (ft_find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	ft_sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = ft_stack_len(*a);
	if (len_a-- > 3 && !ft_stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !ft_stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !ft_stack_sorted(*a))
	{
		ft_init_nodes_a(*a, *b);
		ft_move_a_to_b(a, b);
	}
	ft_sort_three(a);
	while (*b)
	{
		ft_init_nodes_b(*a, *b);
		ft_move_b_to_a(a, b);
	}
	ft_current_index(*a);
	ft_min_on_top(a);
}
