#include "../header/philo.h"

int ft_length_of_char_array(char **av) {
    int length = 0;
    
    while (av[length] != NULL) 
        length++;
    return length;
}

int ft_is_digit(char *str) {
    int i;
    
    i = 0;
    while (str[i]) 
    {
        if (str[i] < '0' || str[i] > '9')
        {
            printf("\033[91mOnly use digits.\033[0m\n");
            return (0);
        }
        i++;
    }
    return (1);
}

int ft_is_valid_arg(char *arg) 
{
    if(ft_atoi(arg) == 0)
    {
        printf("\033[91mNo value should equal to 0.\033[0m\n");
        return (0);
    }
    return (1);
}

int ft_is_valid_nb_meals(char **av, int index) 
{
    if (av[index] && ft_atoi(av[index]) > 200)
    {
        printf("\033[91mThe number of meals should not be superior to 200.\033[0m\n");
        return (0);
    }
    return (1);
}

int ft_check_args(char **av) {
    int len;
    int i;

    len = ft_length_of_char_array(av);
    i = 1;
    while (i < len) {
        if (!ft_is_digit(av[i]) || !ft_is_valid_arg(av[i]))
            return (0);
        i++;
    }
    if (!ft_is_valid_nb_meals(av, 5))
        return (0);
    return (1);
}