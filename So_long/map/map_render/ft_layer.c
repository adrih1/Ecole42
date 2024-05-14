/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_layer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:10:41 by ahors             #+#    #+#             */
/*   Updated: 2024/05/14 18:19:06 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_load_first_layer(t_data *data, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width - 1)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, map->floor, x
				* map->texture_width, y * map->texture_height);
			x++;
		}
		y++;
	}
}

void	ft_load_second_layer(t_data *data, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, map->wall,
					x * map->texture_width, y * map->texture_height);
			x++;
		}
		y++;
	}
}

void	ft_load_third_layer(t_data *data, t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->grid[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					map->collectable, x * map->texture_width, y
					* map->texture_height);
			else if (map->grid[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, map->exit,
					x * map->texture_width, y * map->texture_height);
			else if (map->grid[y][x] == 'P')
			{
				map->player_col = x * map->texture_width;
				map->player_row = y * map->texture_height;
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					map->player, map->player_col, map->player_row);
			}
		}
	}
}
