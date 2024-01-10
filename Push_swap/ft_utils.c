#include "push_swap.h"


void    ft_cost_analaysis(t_stack_node  *a, t_stack_node *b)
{
    int len_a;
    int len_b;

    len_a = ft_stack_len(a);
    len_b = ft_stack_len(b);
    while(a)
    {
        a->push_cost = a->index: 
        if(!(a->above_median))
            a->push_cost = len_a - (a->index);
        if(a->target_node->above_median)
            a->push_cost += a->target_node->index;
        else
            a->push_cost += len_b - (a->target_node->index);
        a = a->next;
    }
}

void    ft_set_cheapest(t_stack_node *stack)
{
    long            cheapest_value;
    t_stack_node    *cheapest_node;

    if(!stack)
        return ;
    cheapest_value = LONG_MAX;
    while(stack)
    {
        if(stack->push_cost < cheapest_value)
        {
            cheapest_value = stack->push_cost;
            cheapest_node = stack;
        }
        stack = stack->next; 
    }
    cheapest_node -> cheapest = true; 

}

void    ft_move_a_to_b(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *cheapest_node; 

    cheapest_node = ft_get_cheapest(*a);
    if(cheapest_node -> above_median && cheapest_node -> target_node -> above_median)
        ft_rotate_both(a, b, cheapest_node);
    else if (!(cheapest_node -> above_median) && !(cheapest_node -> target_node -> above_median))
        ft_rev_rotate_both(a, b, cheapest_node);
    ft_prep_for_push(a, cheapest_node, 'a');
    ft_prep_for_push(b, cheapest_node->target_node, 'b');
    pb(b, a, false);
}

void    ft_move_b_to_a(t_stack_node **a, t_stack_node **b)
{
    ft_prep_for_push(a, (*b) -> target_node, 'a');
    pa(a, b, false);
}


void    ft_min_on_top(t_stack_node **a)
{
    while((*a) -> nbr != ft_find_min(*a) -> nbr)
    {
        if(ft_find_min(*a) -> above_median)
            ra(a, false);
        else
            rra(a, false);
    }
}