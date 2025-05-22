/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check_unknown_chars.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:54:35 by ahors             #+#    #+#             */
/*   Updated: 2024/06/19 15:54:28 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_map_check_unknown_chars(t_map *map)
{
	int	i;
	int	j;

	if (map == NULL)
		return (0);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < (map->width - 1) && map->grid[i][j])
		{
			if (map->grid[i][j] != '0' && map->grid[i][j] != '1'
				&& map->grid[i][j] != 'E' && map->grid[i][j] != 'C'
				&& map->grid[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
