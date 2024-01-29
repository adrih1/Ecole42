/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:16:19 by ahors             #+#    #+#             */
/*   Updated: 2023/11/14 11:07:09 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dest, char *src)
{
	size_t	i;
	size_t	dest_len;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	len_totale;

	if (!s1 || !s2)
		return (NULL);
	len_totale = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	new_string = (char *)malloc(sizeof(char) * (len_totale));
	if (!new_string)
		return (NULL);
	new_string[0] = '\0';
	new_string = ft_strcat(ft_strcat(new_string, (char *)s1), (char *)s2);
	return (new_string);
}
