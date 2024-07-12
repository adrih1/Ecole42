/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:48:01 by ahors             #+#    #+#             */
/*   Updated: 2024/07/12 17:15:07 by ahors            ###   ########.fr       */
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

void	ft_display_map_errors(t_map *map)
{
	if (map->start_count > 1)
		ft_printf("One player at a time\n");
	else if (map->start_count < 1)
		ft_printf("There is no player\n");
	else if (map->exit_count > 1)
		ft_printf("There must be only one exit\n");
	else if (map->exit_count < 1)
		ft_printf("There is not exit\n");
	else if (map->item_count < 1)
		ft_printf("There are no items to be collected\n");
	else if (!ft_check_rectangular(map))
		ft_printf("The map is not rectangular\n");
	else if (!ft_validate_walls(map))
		ft_printf("There is an issue with the walls \n");
	else if (!ft_map_check_unknown_chars(map))
		ft_printf("There is an unknow character\n");
}

int	ft_check_map(int fd, char *filename, t_map *map)
{
	ft_init_map(map);
	ft_parse_map(map, fd, filename);
	ft_get_map_width(map);
	ft_check_exit(map);
	ft_check_items(map);
	ft_check_player(map);
	if (map->start_count != 1 || (map->exit_count != 1) || map->item_count < 1
		|| !ft_validate_walls(map) || !ft_check_rectangular(map)
		|| !ft_map_check_unknown_chars(map))
	{
		ft_display_map_errors(map);
		return (0);
	}
	if (ft_check_path_exists(map) == false)
	{
		ft_printf("This map is impossible\n");
		return (0);
	}
	return (1);
}

void	ft_map_generate(t_map *map, t_data *data)
{
	ft_load_textures1(map, data);
	ft_load_textures2(map, data);
	ft_put_textures(data, map);
}
