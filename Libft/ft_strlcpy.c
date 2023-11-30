/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:21:23 by ahors             #+#    #+#             */
/*   Updated: 2023/11/07 20:22:02 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[i] && size != 0)
	{
		if (i < size - 1)
		{
			dest[j] = src[i];
			j++;
		}
		i++;
	}
	if (size != 0)
		dest[j] = '\0';
	return (ft_strlen((char *)src));
}
