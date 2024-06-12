/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_unknown_chars.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:54:35 by ahors             #+#    #+#             */
/*   Updated: 2024/06/12 12:05:49 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_map_check_unknown_chars(t_map *map)
{
	int	i;
	int	j;

	if (map == NULL)
		return ;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->grid[i][j] && j < map->width - 1)
		{
			if (map->grid[i][j] != '0' || map->grid[i][j] != '1' || map->grid[i][j] != 'E' || map->grid[i][j] != 'C' || map->grid[i][j] != 'P')
                return (0);
			j++;
		}
		i++;
	}
    if (map->grid[i][j] != '0' || map->grid[i][j] != '1' || map->grid[i][j] != 'E' || map->grid[i][j] != 'C' || map->grid[i][j] != 'P')
        return (0);
    return (1);
}