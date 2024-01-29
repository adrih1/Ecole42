/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:15:57 by ahors             #+#    #+#             */
/*   Updated: 2023/11/16 14:49:29 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new_string;
	unsigned int	i;
	size_t			s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		new_string = malloc(1);
		if (new_string)
			new_string[0] = '\0';
		return (new_string);
	}
	if (start + len > s_len)
		len = s_len - start;
	new_string = malloc((len + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
		new_string[i++] = s[start++];
	new_string[i] = '\0';
	return (new_string);
}
