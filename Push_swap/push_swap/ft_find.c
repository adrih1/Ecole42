#include "push_swap.h"

//Stack length
int ft_stack_len(t_stack_node *stack)
{
    int i;

    i = 0;
    while (*stack -> next)
    {
        *stack = *stack -> next; 
        i++;
    }
    return (i);
}

//Find the last node 
ft_find_last_node(t_stack_node *stack);

//Min and max nodes
ft_find_max(t_stack_node *b)
{

}

ft_find_min(t_stack_node *a)
{

}

ft_get_cheapest(); 