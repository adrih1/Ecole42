/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_route.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:01:53 by ahors             #+#    #+#             */
/*   Updated: 2024/07/12 15:34:50 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_flood_fill_util(t_map *map, int x, int y)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height
		|| map->visited[y][x] || map->grid[y][x] == '1')
		return ;
	map->visited[y][x] = true;
	if (map->grid[y][x] == 'C')
		map->item_count_flood_fill--;
	if (map->grid[y][x] == 'E')
	{
		map->exit_x = x;
		map->exit_y = y;
		map->exit_found = true;
	}
	ft_flood_fill_util(map, x + 1, y);
	ft_flood_fill_util(map, x - 1, y);
	ft_flood_fill_util(map, x, y + 1);
	ft_flood_fill_util(map, x, y - 1);
	if (map->exit_found && map->item_count_flood_fill == 0)
		return ;
}

bool	ft_check_path_exists(t_map *map)
{
	int	i;

	i = 0;
	map->visited = (bool **)malloc(map->height * sizeof(bool *));
	if (!(map->visited))
		ft_free_all(map);
	while (i < map->height)
	{
		map->visited[i] = ft_calloc(map->width, sizeof(bool));
		i++;
	}
	ft_flood_fill_util(map, map->player_col, map->player_row);
	return (map->exit_found && (map->item_count_flood_fill == 0));
}
