/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:08:14 by ahors             #+#    #+#             */
/*   Updated: 2023/11/20 16:01:17 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*tempdest;
	const char	*tempsrc;

	tempdest = (char *)dest + n - 1;
	tempsrc = (const char *)src + n - 1;
	if (dest < src)
	{
		ft_memcpy(dest, src, n);
	}
	else if (dest > src)
	{
		while (n--)
		{
			*tempdest = *tempsrc;
			tempdest = tempdest - 1;
			tempsrc = tempsrc - 1;
		}
	}
	return (dest);
}
// int	main()
// {
// 	char src[] = "Hello, World!";
// 	char dest[] = "Welcome to the World!";
// 	ft_memmove(dest + 7, dest, 13);
// }
