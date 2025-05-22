/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:48:51 by ahors             #+#    #+#             */
/*   Updated: 2024/07/16 10:19:04 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	*ft_load_image(void *mlx_ptr, char *file_path, int *width, int *height)
{
	void	*img_ptr;

	img_ptr = mlx_xpm_file_to_image(mlx_ptr, file_path, width, height);
	if (!img_ptr)
		return (NULL);
	return (img_ptr);
}

void	ft_load_textures1(t_map *map, t_data *data)
{
	map->floor = ft_load_image(data->mlx_ptr, "assets/floor.xpm",
			&map->texture_width, &map->texture_height);
	if (!(map->floor))
	{
		ft_printf("There was an issue with the floor texture\n");
		ft_free_all(map);
		exit(0);
	}
	map->exit = ft_load_image(data->mlx_ptr, "assets/open-exit.xpm",
			&map->texture_width, &map->texture_height);
	if (!(map->exit))
	{
		ft_printf("There was an issue with the exit texture 🚪\n");
		ft_free_all(map);
		exit(0);
	}
}

void	ft_load_textures2(t_map *map, t_data *data)
{
	map->wall = ft_load_image(data->mlx_ptr, "assets/wall.xpm",
			&map->texture_width, &map->texture_height);
	if (!(map->wall))
	{
		ft_printf("There was an issue with the wall texture 🧱\n");
		ft_free_all(map);
		exit(0);
	}
	map->player = ft_load_image(data->mlx_ptr, "assets/front.xpm",
			&map->texture_width, &map->texture_height);
	if (!(map->player))
	{
		ft_printf("There was an issue with the player texture 👤\n");
		ft_free_all(map);
		exit(0);
	}
	map->collectable = ft_load_image(data->mlx_ptr, "assets/coin-bag.xpm",
			&map->texture_width, &map->texture_height);
	if (!(map->collectable))
	{
		ft_printf("There was an issue with the collectable texture 🪙\n");
		ft_free_all(map);
		exit(0);
	}
}

void	ft_put_textures(t_data *data, t_map *map)
{
	ft_load_first_layer(data, map);
	ft_load_second_layer(data, map);
	ft_load_third_layer(data, map);
	ft_load_fourth_layer(data, map);
}
