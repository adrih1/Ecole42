/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mobility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:11:05 by ahors             #+#    #+#             */
/*   Updated: 2024/05/14 18:49:25 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move_up(t_map *map, int i, int j)
{
	int	new_i;
	int	new_j;

	new_i = i;
	new_j = j - 1;
	if (new_j >= 0 && ft_move_game_finish(map->grid[new_j][new_i], map))
	{
		map->grid[j][i] = '0';
		map->grid[new_j][new_i] = 'P';
		map->player_row -= 32;
		ft_put_textures(map->data, map);
	}
}

void	ft_move_down(t_map *map, int i, int j)
{
	int	new_i;
	int	new_j;

	new_i = i;
	new_j = j + 1;
	if (new_j >= 0 && ft_move_game_finish(map->grid[new_j][new_i], map))
	{
		map->grid[j][i] = '0';
		map->grid[new_j][new_i] = 'P';
		map->player_row += 32;
		ft_put_textures(map->data, map);
	}
}

void	ft_move_left(t_map *map, int i, int j)
{
	int	new_i;
	int	new_j;

	new_i = i - 1;
	new_j = j;
	if (new_i >= 0 && ft_move_game_finish(map->grid[new_j][new_i], map))
	{
		map->grid[j][i] = '0';
		map->grid[new_j][new_i] = 'P';
		map->player_col -= 32;
		ft_put_textures(map->data, map);
	}
}

void	ft_move_right(t_map *map, int i, int j)
{
	int	new_i;
	int	new_j;

	new_i = i + 1;
	new_j = j;
	if (new_i >= 0 && ft_move_game_finish(map->grid[new_j][new_i], map))
	{
		map->grid[j][i] = '0';
		map->grid[new_j][new_i] = 'P';
		map->player_col += 32;
		ft_put_textures(map->data, map);
	}
}

void	ft_get_player_coordinate(t_map *map, int keynum)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	i = map->player_col / 32;
	j = ((map->player_row) / 32);
	if (keynum == 119)
		ft_move_up(map, i, j);
	if (keynum == 115)
		ft_move_down(map, i, j);
	if (keynum == 97)
		ft_move_left(map, i, j);
	if (keynum == 100)
		ft_move_right(map, i, j);
}
