/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:17:19 by ahors             #+#    #+#             */
/*   Updated: 2024/01/18 14:55:52 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

// Functions to handle errors
int	ft_error_syntax(char *argv)
{
	// int i = 0;

	// if argv[i] == + ou -
	// i++
	// if qartgv == 0 
	// 	return (0);
	// while (argv[i])
	// 	if !is digit (argv[]i)
	// 		return(0);
	// 	i++;
	// return 1

	if (!(*argv == '+' || *argv == '-' || (*argv >= '0' && *argv <= '9')))
		return (1);
	if ((*argv == '+' || *argv == '-') && !(argv[1] >= '0' && argv[1] <= '9'))
		return (1);
	while (*++argv)
	{
		if (!(*argv >= '0' && *argv <= '9'))
			return (1);
	}
	return (0);
}

int	ft_error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	ft_free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	ft_free_errors(t_stack_node **a)
{
	ft_free_stack(a);
	write(1, "Error\n", 6);
	exit(1);
}
