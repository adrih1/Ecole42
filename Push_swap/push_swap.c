#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack_node *a;
    t_stack_node *b;

    a = NULL;
    b = NULL;

    if(argc == 1 || argc == 2 && !argv[1][0])
        return (1);
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');
    ft_init_stack(&a, argv + 1);
    if(!ft_stack_sorted(a))
    {
        if(ft_stack_len(a) == 2)
            sa(&a, false);
        else if(ft_stack_len(a) == 3)
            ft_sort_three(&a);
        else
            ft_sort_stacks(&a, &b);
    }
    ft_free_stack(&a);
    return (0);
}