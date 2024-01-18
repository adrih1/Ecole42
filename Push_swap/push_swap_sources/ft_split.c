/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:23:26 by ahors             #+#    #+#             */
/*   Updated: 2024/01/18 09:11:57 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	ft_count_words(char *string, char delimeter)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*string)
	{
		inside_word = false;
		while (*string == delimeter)
			++string;
		while (*string != delimeter && *string)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

static char	*ft_get_next_word(char *s, char delimeter)
{
	static int	cursor;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	cursor = 0;
	while (s[cursor] == delimeter)
		++cursor;
	while ((s[cursor + len] != delimeter) && s[cursor + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != delimeter) && s[cursor]) 
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

char **ft_split(char *string, char delimeter)
{
	int		words_count;
	char	**result_array;
	int		i;

	i = 0;
	words_count = ft_count_words(string, delimeter);
	if (!words_count)
		exit(1);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2));
	if (!result_array)
		return (NULL);
	while (words_count-- >= 0)
	{
		if (i == 0)
		{
			result_array[i] = malloc(sizeof(char));
			if (!result_array[i])
				return (NULL);
			result_array[i++][0] = '\0';
			continue ;
		}
		result_array[i++] = ft_get_next_word(string, delimeter);
	}
	result_array[i] = NULL;
	return (result_array);
}
