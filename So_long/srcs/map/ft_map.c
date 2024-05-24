/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:48:01 by ahors             #+#    #+#             */
/*   Updated: 2024/05/24 14:14:32 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->grid = NULL;
	map->start_count = 0;
	map->exit_count = 0;
	map->item_count = 0;
	map->item_count_flood_fill = 0;
	map->player_row = 0;
	map->player_col = 0;
	map->wall = NULL;
	map->exit = NULL;
	map->floor = NULL;
	map->player = NULL;
	map->collectable = NULL;
	map->data = NULL;
	map->visited = NULL;
	map->exit_found = false;
}

int	ft_check_map(int fd, char *filename, t_map *map)
{
	ft_init_map(map);
	ft_parse_map(map, fd, filename);
	ft_get_map_width(map);
	ft_check_exit(map);
	ft_check_start(map);
	ft_check_items(map);
	ft_check_player(map);
	if (map->start_count > 1 || map->exit_count == 0 || map->item_count < 1
		|| !ft_validate_walls(map) || !ft_check_rectangular(map))
	{
		return (0);
	}
	if(ft_check_path_exists(map) == false)
		return (0);			
	return (1);
}

void	ft_render_texture(t_data data, char *filename, int img_width,
		int img_height, int j, int i)
{
	void	*img_ptr;

	img_ptr = ft_load_image(data.mlx_ptr, filename, &img_width, &img_height);
	if (!img_ptr)
		ft_printf("L'image n'existe pas.\n");
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img_ptr, j * img_width,
		i * img_height);
}

void	ft_map_generate(t_map *map, t_data *data)
{
	ft_load_textures1(map, data);
	ft_load_textures2(map, data);
	ft_put_textures(data, map);
}
