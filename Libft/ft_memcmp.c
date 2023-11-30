/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:24:30 by ahors             #+#    #+#             */
/*   Updated: 2023/11/13 11:37:33 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1bis;
	const unsigned char	*s2bis;

	s1bis = (unsigned char *)s1;
	s2bis = (unsigned char *)s2;
	i = 0;
	while (i < n - 1 && s1bis[i] == s2bis[i])
		i++;
	if (i == n || n == 0)
		return (0);
	return (s1bis[i] - s2bis[i]);
}
