/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:05:14 by ahors             #+#    #+#             */
/*   Updated: 2023/11/16 11:12:15 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	s_len;
	int	i;

	if (!s)
		return ;
	s_len = ft_strlen(s);
	i = 0;
	while (i < s_len)
	{
		write(fd, &s[i], 1);
		i++;
	}
}
