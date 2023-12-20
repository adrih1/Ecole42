#include "push_swap.h"

//Functions to handle errors
ft_error_syntax(char *argv);
ft_error_duplicate(t_stack_node *a, int nbr);
ft_free_errors(t_stack_node *a);

//Stack length
int ft_stack_len(t_stack_node *stack)
{
    
}
//Init Stacks
void    ft_init_stack(t_stack_node **a, char **argv)
{
    long    nbr;
    int     i;

    i = 0;
    while(argv[i])
    {
        if(ft_error_syntax(argv[i]))
            ft_free_errors(a);
        nbr = ft_atoi(argv[i]);
        if(ft_error_duplicate(*a, (int)nbr))
            ft_free_errors(a);
        ft_append_node(a, (int)nbr);
        i++;
    }
}

//Append Nodes to Stack 
void    ft_append_node(t_stack_node **stack, int n)
{
    t_stack_node    *node;
    t_stack_node    *last_node; 

    if (!stack)
        return;
    node = malloc(sizeof(t_stack_node));
    if (!node)
        return;
    node->next = NULL;
    node->nbr = n;
    if (!(*stack))
    {
        *stack = node;
        node->prev = NULL;
    }
    else
    {
        last_node = ft_find_last_node(*stack);
        last_node->next = node;
        node->prev = last_node;
    }

}


//Find the last node 
ft_find_last_node(t_stack_node *stack);

//Min and max nodes
ft_find_max(t_stack_node *a);

ft_find_min(t_stack_node *a);

