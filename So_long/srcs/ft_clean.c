/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:58:18 by ahors             #+#    #+#             */
/*   Updated: 2024/07/16 10:19:16 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_data(t_data *data)
{
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}

void	ft_free_textures(t_map *map)
{
	if (map->wall)
		mlx_destroy_image(map->data->mlx_ptr, map->wall);
	if (map->exit)
		mlx_destroy_image(map->data->mlx_ptr, map->exit);
	if (map->floor)
		mlx_destroy_image(map->data->mlx_ptr, map->floor);
	if (map->player)
		mlx_destroy_image(map->data->mlx_ptr, map->player);
	if (map->collectable)
		mlx_destroy_image(map->data->mlx_ptr, map->collectable);
}

void	ft_free_visited(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->visited[i]);
		i++;
	}
	free(map->visited);
}

void	ft_free_grid(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}

void	ft_free_all(t_map *map)
{
	if (map->grid)
		ft_free_grid(map);
	ft_free_textures(map);
	if (map->data)
		ft_free_data(map->data);
	if (map->visited)
		ft_free_visited(map);
	if (map)
		free(map);
}
