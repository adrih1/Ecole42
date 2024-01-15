#include "../header/push_swap.h"

void    ft_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
    while(*b != cheapest_node->target_node && *a != cheapest_node)
        rr(a, b, false);
    ft_current_index(*a);
    ft_current_index(*b);
}

void	ft_rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, false);
	ft_current_index(*a);
	ft_current_index(*b);
}