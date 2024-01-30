/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:25:58 by ahors             #+#    #+#             */
/*   Updated: 2024/01/30 14:43:57 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"


void	print_stack_nodes(t_stack_node *head)
{
	t_stack_node	*current;

	current = head;
	while (current != NULL)
	{
		printf("%d\n", current->nbr);
		current = current->next;
	}
}
