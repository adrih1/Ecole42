/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:56:37 by ahors             #+#    #+#             */
/*   Updated: 2023/11/14 11:05:12 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	while (((char *)s)[s_len] != (char)c && s_len > 0)
	{
		s_len--;
	}
	if (s_len == 0 && ((char *)s)[0] != (char)c)
	{
		return (NULL);
	}
	return (&((char *)s)[s_len]);
}
