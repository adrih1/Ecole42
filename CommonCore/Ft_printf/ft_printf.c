/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:58:03 by ahors             #+#    #+#             */
/*   Updated: 2023/11/27 16:18:04 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_format_letter(const char *format, va_list *args)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += ft_putchar(va_arg(*args, int));
	else if (*format == 's')
		count += ft_putstr(va_arg(*args, char *));
	else if (*format == 'p')
		count += ft_putpointer(va_arg(*args, void *));
	else if (*format == 'd' || *format == 'i')
		count += ft_putnbr(va_arg(*args, int));
	else if (*format == 'u')
		count += ft_putnbr_base_unsigned(va_arg(*args, unsigned int),
				"0123456789");
	else if (*format == 'x')
		count += ft_putnbr_base_unsigned(va_arg(*args, int),
				"0123456789abcdef");
	else if (*format == 'X')
		count += ft_putnbr_base_unsigned(va_arg(*args, int),
				"0123456789ABCDEF");
	else if (*format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_handle_format_letter(format, &args);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
