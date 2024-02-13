/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:48:01 by ahors             #+#    #+#             */
/*   Updated: 2024/02/13 10:11:55 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_free_map(t_map *map)
{
    int i;

    i = 0;
    while (i < map->height)
    {
        free(map->grid[i]);
        i++;
    }
    free(map->grid);
}

void    ft_init_map(t_map *map)
{
    map->width = 0;
    map->height = 0;
    map->grid = NULL;
    map->exit_count = 0;
    map->item_count = 0;
    map->start_count = 0;
}

int ft_check_map(int fd, char *filename, t_map *map)
{
    ft_init_map(map);
    ft_parse_map(map, fd, filename);
    ft_get_map_width(map);
    ft_check_exit(map);
    ft_check_start(map);
    ft_check_items(map);
    if(map->start_count > 1 || map->exit_count > 1 || map->item_count < 1 || !ft_validate_walls(map) || !ft_check_rectangular(map))
    {
        ft_free_map(map);
        //Afficher Erreur 
        return (0);
    }
    return (1);
}

void	ft_render_texture(t_data data, char *filename, int img_width, int img_height, int j, int i)
{
    void *img_ptr;

	img_ptr = ft_load_image(data.mlx_ptr, filename, &img_width, &img_height);
    if (!img_ptr)
    {
        free(img_ptr);
        ft_printf("L'image n'existe pas.\n");
    }
    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img_ptr, j*img_width, i*img_height);
}


// void    ft_map_generate(t_map *map, t_data *data)
// {
//     int i;
//     int j;

//     i = 0;
//     while(map->grid[i] && (i <= map->height - 1))
//     {     
//         j = 0;
//         while(map->grid[i][j])
//         {
//             if(map->grid[i][j] == '0')
//                 ft_render_texture(*data, "assets/floor.xpm", map->texture_width, map->texture_height, j, i);
//             if(map->grid[i][j] == '1')
//                 ft_render_texture(*data, "assets/wall.xpm", map->texture_width, map->texture_height, j, i);
//             if(map->grid[i][j] == 'C')
//                 ft_render_texture(*data, "assets/coin-bag.xpm", map->texture_width, map->texture_height, j, i);
//             if(map->grid[i][j]== 'E')
//                 ft_render_texture(*data, "assets/open-exit.xpm", map->texture_width, map->texture_height, j, i);
//             if(map->grid[i][j] == 'P')
//             {
//                 map->player_col = j * map->texture_width;
//                 map->player_row = i * map->texture_height;
//                 ft_render_texture(*data, "assets/front.xpm", map->texture_width, map->texture_height, j, i);
//             } 
//             j++;
//         }
//         i++;
//     }
// }

void    ft_map_generate(t_map *map, t_data *data)
{
	ft_load_textures(map, data);
	ft_put_textures(data, map);
}