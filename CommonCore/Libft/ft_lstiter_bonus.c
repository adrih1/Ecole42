/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:07:44 by ahors             #+#    #+#             */
/*   Updated: 2023/11/17 12:01:13 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	int	list_size;
	int	i;

	list_size = ft_lstsize(lst);
	i = 0;
	while (i < list_size)
	{
		f((void *)lst->content);
		lst = lst->next;
		i++;
	}
}
