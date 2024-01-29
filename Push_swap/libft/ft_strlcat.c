/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:27:13 by ahors             #+#    #+#             */
/*   Updated: 2023/11/14 15:42:32 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	j;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	dest_len = ft_strlen(dest);
	if (dest_len >= size)
		return (src_len + size);
	else
	{
		j = 0;
		while (j < size - dest_len - 1 && src[j])
		{
			dest[j + dest_len] = src[j];
			j++;
		}
		dest[dest_len + j] = '\0';
	}
	return (dest_len + src_len);
}
