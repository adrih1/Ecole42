#include "push_swap.h"

void    ft_current_index(t_stack_node *stack)
{
    int i;
    int median; 

    i = 0;
    if (!stack)
        return;
    median = ft_stack_len(stack) / 2;
    while(stack)
    {
        stack->index = i;
        if (i <= median)
            stack->above_median = true;
        else
            stack->above_median = false;
        stack = stack->next;
        ++i;
    }
    
}

void    ft_set_target_a(t_stack_node *a, t_stack_node *b)
{
    t_stack_node    *current_b;
    t_stack_node    *target_node;
    long            best_match_index;

    while(a)
    {
        best_match_index = LONG_MIN;
        current_b = b;
        while (current_b)
        {
            if((current_b->nbr < a->nbr) 
            && (current_b->nbr > best_match_index))
            {
                best_match_index = current_b ->nbr;
                target_node = current_b;
            }
            current_b = current_b->next;
        }
        if(best_match_index == LONG_MIN)
            a->target_node = ft_find_max(b);
        else
            a->target_node = target_node;
        a = a->next;
    }
}

void    ft_cost_analaysis(t_stack_node  *a; t_stack_node *b)
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

    }
}