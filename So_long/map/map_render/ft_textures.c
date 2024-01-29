/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:48:51 by ahors             #+#    #+#             */
/*   Updated: 2024/01/29 16:49:09 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void    ft_load_textures(t_map *map, t_data *data)
{

    map->floor = mlx_xpm_file_to_image(data->mlx_ptr, "../../assets/floor.xpm", &map->texture_width, &map->texture_height);
    if(!(map->floor))
    {
        ft_printf("Floor\n");
        ft_free_textures(data, map);
        exit(0);
    }
    map->exit = mlx_xpm_file_to_image(data->mlx_ptr, "../../assets/open-exit.xpm", &map->texture_width, &map->texture_height);
    if(!(map->exit))
    {
        ft_printf("Exit\n");
        ft_free_textures(data, map);
        exit(0);
    }
    map->wall = mlx_xpm_file_to_image(data->mlx_ptr, "../../assets/wall.xpm", &map->texture_width, &map->texture_height);
    if(!(map->wall))
    {
        ft_printf("Wall\n");
        ft_free_textures(data, map);
        exit(0);
    }
    map->player = mlx_xpm_file_to_image(data->mlx_ptr, "../../assets/front.xpm", &map->texture_width, &map->texture_height);
    if(!(map->player))
    {
        ft_printf("Player\n");
        ft_free_textures(data, map);
        exit(0);
    }
    
}

void ft_put_textures(t_data *data, t_map *map)
{
	ft_load_first_layer(data, map);
	ft_load_second_layer(data, map);
	ft_load_third_layer(data, map);
}

void ft_free_textures(t_data *data, t_map *map)
{
    ft_printf("Free Textures\n");
	if (map->wall)
		mlx_destroy_image(data->mlx_ptr, map->wall);
	if (map->floor)
		mlx_destroy_image(data->mlx_ptr, map->floor);
	if (map->exit)
		mlx_destroy_image(data->mlx_ptr, map->exit);
	if (map->player)
		mlx_destroy_image(data->mlx_ptr, map->player);
}