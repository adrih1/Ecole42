/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:59:35 by ahors             #+#    #+#             */
/*   Updated: 2023/11/30 10:59:36 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long int nbr)
{
	size_t	len;

	len = 0;
	if (nbr < 0)
	{
		len += ft_putchar('-');
		nbr = nbr * (-1);
	}
	if (nbr >= 10)
	{
		len += ft_putnbr(nbr / 10);
		len += ft_putnbr(nbr % 10);
	}
	else
		len += ft_putchar(nbr + '0');
	return (len);
}
