#include "../header/push_swap.h"


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