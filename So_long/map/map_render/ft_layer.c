/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_layer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:10:41 by ahors             #+#    #+#             */
/*   Updated: 2024/01/29 16:19:39 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"


void ft_load_first_layer(t_data *data, t_map *map)
{
	int y;
	int x;

	y = 0;
	while (y < map->height - 1)
	{
		x = 0;
		while (x < map->width)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, map->floor, x * map->texture_width, y * map->texture_height);
			x++;
		}
		y++;
	}
}



void ft_load_second_layer(t_data *data, t_map *map)
{
	int y;
	int x;

	y = 0;
	while (y < map->height - 1)
	{
		x = 0;
		while (x < map->width)
		{
            if(map->grid[y][x] == '1')
			    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, map->wall, x * map->texture_width, y * map->texture_height);
			x++;
		}
		y++;
	}
}


void ft_load_third_layer(t_data *data, t_map *map)
{
	int y;
	int x;

	y = 0;
	while (y < map->height - 1)
	{
		x = 0;
		while (x < map->width)
		{
            if(map->grid[y][x] == 'C')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, map->collectable, x * map->texture_width, y * map->texture_height);
            else if(map->grid[y][x]== 'E')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, map->exit, x * map->texture_width, y * map->texture_height);
            else if (map->grid[y][x] == 'P')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, map->player, x * map->texture_width, y * map->texture_height);
			x++;
		}
		y++;
	}
}