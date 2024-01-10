#include "push_swap.h"

void    rr(t_stack_node **a, t_stack_node **b, bool print)
{
    rotate(a);
    rotate(b);
    if(!print)
        write(1, "rr\n", 3);
}

void    ft_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
    while(*b != cheapest_node->target_node && *a != cheapest_node)
        rr(a, b, false);
    ft_current_index(*a);
    ft_current_index(*b);
}