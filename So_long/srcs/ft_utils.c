/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:48:08 by ahors             #+#    #+#             */
/*   Updated: 2024/06/11 12:58:36 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_close_file(int fd)
{
	close(fd);
}

int	ft_open_file(char *filename)
{
	int	fd;

	if (!filename)
		exit(1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Probleme pour pour ouvrir le fichier");
		exit(1);
	}
	return (fd);
}
