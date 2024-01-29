/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:07:52 by ahors             #+#    #+#             */
/*   Updated: 2023/11/20 19:06:01 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_skipsetstart(char const *s1, char const *set)
{
	int	start;

	start = 0;
	while (s1[start] && ft_isset((char *)set, s1[start]))
	{
		start++;
	}
	return (start);
}

static int	ft_skipsetend(char const *s1, char const *set)
{
	int	end;

	end = ft_strlen(s1) - 1;
	while (end >= 0 && ft_isset((char *)set, s1[end]))
	{
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trimstring;

	if (!s1 || !set)
		return (NULL);
	start = ft_skipsetstart(s1, set);
	end = ft_skipsetend(s1, set);
	if (start > end)
	{
		trimstring = (char *)malloc(1);
		if (!trimstring)
			return (NULL);
		trimstring[0] = '\0';
		return (trimstring);
	}
	trimstring = ft_substr(s1, start, end - start + 1);
	return (trimstring);
}
