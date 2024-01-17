/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:16:22 by ahors             #+#    #+#             */
/*   Updated: 2024/01/17 10:42:50 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

int	ft_str_is_numeric(char str)
{
    if (!(str >= 48 && str <= 57))
    {
        return (0);
    }
    return (1);
}

int	ft_isspace(char c)
{
    if ((c >= '\t' && c <= '\r') || c == ' ')
        return (1);
    return (0);
}

long ft_atol(char *str)
{
    int		i;
    long	res;
    int		sign;

    i = 0;
    res = 0;
    sign = 1;
    while (str[i] != '\0' && ft_isspace(str[i]) == 1)
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = sign * -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res * sign);
}
