/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:23:51 by ahors             #+#    #+#             */
/*   Updated: 2024/01/17 09:27:19 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

bool	ft_stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	ft_prep_for_push(t_stack_node **stack, t_stack_node *top_node,
		char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new_string;
	unsigned int	i;
	size_t			s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen((char *)s);
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


void ft_free_argv(char **argv) {
    if (argv == NULL) {
        return;
    }
    int i = 0;
    while (argv[i] != NULL) {
        free(argv[i]);
        i++;
    }
    free(argv);
}
