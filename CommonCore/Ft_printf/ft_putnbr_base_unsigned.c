/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:59:18 by ahors             #+#    #+#             */
/*   Updated: 2023/11/30 10:59:20 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_recursive_unsigned(unsigned int nbr, char *base,
		int *recursion_count)
{
	unsigned int	base_len;

	base_len = ft_base_len(base);
	(*recursion_count)++;
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
		(*recursion_count)++;
	}
	if (nbr < base_len)
		ft_putchar(base[nbr]);
	else
	{
		ft_putnbr_base_recursive_unsigned(nbr / base_len, base,
			recursion_count);
		ft_putchar(base[nbr % base_len]);
	}
}

int	ft_putnbr_base_unsigned(unsigned int nbr, char *base)
{
	int	recursion_count;

	recursion_count = 0;
	ft_putnbr_base_recursive_unsigned(nbr, base, &recursion_count);
	return (recursion_count);
}
