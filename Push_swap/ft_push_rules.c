#include "push_swap.h"

void    ft_prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
    while(*stack != top_node)
    {
        if(stack_name == 'a')
        {
            if(top_node->above_median)
                ra(stack, false);
            else 
                rra(stack, false);
        }
        else if(stack_name == 'b')
        {
             if(top_node->above_median)
                rb(stack, false);
            else 
                rrb(stack, false);
        }

    }
}