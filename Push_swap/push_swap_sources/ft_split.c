/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:23:26 by ahors             #+#    #+#             */
/*   Updated: 2024/01/16 14:23:41 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static char	*ft_cpy_words(const char *str, char c)
{
	size_t	count;
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	count = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] == c)
	{
		i++;
		j++;
	}
	while (str[j] && str[j] != c)
	{
		count++;
		j++;
	}
	ptr = ft_substr(str, i, count);
	return (ptr);
}

static int	ft_count_word(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] == c && str[i])
		i++;
	while (str[i])
	{
		if ((str[i] == c && str[i + 1] != c) || (str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	ft_free(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char	**ptrs;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	ptrs = malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!ptrs)
		return (NULL);
	while (*s)
	{
		if ((*s != c || *s == '\0'))
		{
			ptrs[i] = ft_cpy_words(s, c);
			if (ptrs[i] == NULL)
				ft_free(ptrs);
			s = s + ft_strlen(ptrs[i] + 1);
			i++;
		}
		s++;
	}
	ptrs[i] = NULL;
	return (ptrs);
}
