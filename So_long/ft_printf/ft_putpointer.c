/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:58:35 by ahors             #+#    #+#             */
/*   Updated: 2023/11/30 11:00:31 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_pointer(unsigned long nb, char *base)
{
	long long	i;
	char		result[100];
	int			len;

	if (nb == 0)
	{
		ft_putchar(base[0]);
		return (1);
	}
	i = 0;
	while (nb > 0)
	{
		result[i] = base[nb % ft_base_len(base)];
		nb /= ft_base_len(base);
		i++;
	}
	len = i;
	while (i > 0)
		ft_putchar(result[i-- - 1]);
	return (len);
}

int	ft_putpointer(void *ptr)
{
	unsigned long	address;
	int				count;

	count = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	address = (unsigned long)ptr;
	write(1, "0x", 2);
	count += ft_putnbr_base_pointer(address, "0123456789abcdef");
	return (count + 2);
}
