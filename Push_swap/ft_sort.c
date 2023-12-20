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

void    ft_sort_three(t_struct_node **a)
{
    t_stack_node    *biggest_node;

    biggest_node = ft_find_max(*a)
}

// ft_sort_stack(t_struct_node *c)