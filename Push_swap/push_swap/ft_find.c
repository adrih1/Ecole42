#include "push_swap.h"

//Stack Length
int ft_stack_len(t_stack_node *stack)
{
    int i;

    i = 0;
    if (!stack) 
		return (0);
    while (stack)
    {
        stack = stack -> next;
        i++;
    }
    return (i);
}

//Find the last node 
t_stack_node    ft_find_last_node(t_stack_node *stack)
{
    if(!stack)
        return (NULL);
    while (stack -> next)
        stack = stack -> next;
    return(stack);
}

//Min and Max Nodes
t_stack_node	*ft_find_max(t_stack_node *stack)
{
    long    max;
    t_stack_node    *max_node;

    if(!stack)
        return (NULL);
    max = LONG_MIN;
    while(stack)
    {
        if(stack->nbr > max)
        {
            max = stack->nbr;
            max_node = stack;
        }
        stack = stack->next;
    }
    return(max_node);

}

t_stack_node	*ft_find_min(t_stack_node *stack)
{
    long    min;
    t_stack_node    *min_node;

    if(!stack)
        return (NULL);
    min = LONG_MAX;
    while(stack)
    {
        if(stack->nbr < min)
        {
            min = stack->nbr;
            min_node = stack;
        }
        stack = stack->next;
    }
    return(min_node);

}


//Cheapest Node
t_stack_node    ft_get_cheapest(t_stack_node *stack)
{
    t_stack_node    *cheapest_node; 

    if(!stack)
        return(NULL);
    while(stack)
    {
        if(stack -> cheapest)
            return(stack);
        stack = stack -> next; 
    }
    return (NULL);
}