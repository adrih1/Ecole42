// Only numbers, they should all be bigger than 0 except the number of meals each philo needs to eat (edge case). 
// We should not test with more than 200 philos --> set the limit not to be more than 200.

#include "../header/philo.h"

int ft_length_of_char_array(char **av) {
    int length = 0;
    
    while (av[length] != NULL) 
        length++;
    return length;
}

int ft_check_args(char **av)
{
    int len;
    int i;
    int j;

    len = ft_length_of_char_array(av);
    i = 1;
    while(i < len)
    {
        j = 0;
        while(av[i][j])
        {
            if(av[i][j] < '0' || av[i][j] > '9')
                return(0);
            j++;
        }
        i++;
    }
    if(av[5] && ft_atoi(av[5]) > 200)
    {
        printf("Meals should not be superior to 200\n");
        return (0);
    }
    return (1);

}



// void	ft_free_array(char **argv)
// {
// 	int i;
// 	int len;

// 	i = 0;
// 	len = length_of_char_array(argv);
// 	printf("len of argv: %d\n", len);
// 	while(i < len)
// 	{
// 		free(argv[i]);
// 		i++;
// 	}
// 	free(argv);
// }