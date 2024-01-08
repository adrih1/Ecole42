#include "push_swap.h"

bool    ft_stack_sorted(t_stack_node *stack)
{
    if(!stack)
        return(1);
    while(stack->next)
    {
        if(stack->nbr > stack->next->nbr)
            return (false);
        stack = stack->next;
    }
    return (true);
}

void    ft_sort_three(t_stack_node **a)
{
    t_stack_node    *biggest_node;

    biggest_node = ft_find_max(*a); 
    if(biggest_node == *a)
        ra(a, false);
    else if(biggest_node == (*a) -> next)
        rra(a, false);
    if((*a)->nbr > (*a)->next->nbr)
        sa(a, false);
}

void    ft_sort_stacks(t_struct_node **a, t_stack_node **b)
{
    int len_a;

    len_a = ft_stack_len(*a);
    if(len_a-- > 3 && !ft_stack_sorted(*a))
        pb(b, a, false);
    if(len_a-- > 3 && !ft_stack_sorted(*a))
        pb(b, a, false);
    while(len_a-- > 3 && !ft_stack_sorted(*a))
    {
        ft_init_nodes_a(*a, *b);
        ft_move_a_to_b(a, b);
    }
}