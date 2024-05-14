/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:48:13 by ahors             #+#    #+#             */
/*   Updated: 2024/05/14 18:10:46 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_validate_columns(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][map->width - 2] != '1')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_validate_rows(t_map *map)
{
	int	i;

	i = 0;
	map->width -= 2;
	while (i < map->width)
	{
		if (map->grid[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->width)
	{
		if (map->grid[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	map->width += 2;
	return (1);
}

int	ft_validate_walls(t_map *map)
{
	if (ft_validate_columns(map) && ft_validate_rows(map))
		return (1);
	return (0);
}
