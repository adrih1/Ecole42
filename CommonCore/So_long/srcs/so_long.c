/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:48:04 by ahors             #+#    #+#             */
/*   Updated: 2024/07/16 10:19:29 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map **map)
{
	*map = (t_map *)malloc(sizeof(t_map));
	if (!*map)
	{
		ft_free_all(*map);
		exit(1);
	}
}

void	check_map_file(int *fd, char *filename, t_map *map)
{
	if (ft_check_map(*fd, filename, map) == 0)
	{
		ft_free_all(map);
		exit(1);
	}
}

void	init_mlx(t_data *data, t_map *map)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_free_all(map);
		exit(1);
	}
}

void	create_window(t_data *data, t_map *map)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, ((map->width - 1) * 32),
			(map->height * 32), "My first game !");
	if (!data->win_ptr)
	{
		free(data->win_ptr);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	t_map	*map;
	char	*filename;
	int		fd;

	if (ac != 2)
		ft_printf("Please give a .ber file for the map\n");
	filename = av[1];
	fd = ft_open_file(filename);
	init_map(&map);
	check_map_file(&fd, filename, map);
	close(fd);
	init_mlx(&data, map);
	create_window(&data, map);
	map->data = &data;
	map->data->random_num = 6;
	map->texture_height = 32;
	map->texture_width = 32;
	ft_map_generate(map, map->data);
	mlx_hook(data.win_ptr, 2, 1L << 0, on_keypress, map);
	mlx_hook(data.win_ptr, 17, 1L << 4, on_destroy, map);
	mlx_loop(data.mlx_ptr);
	return (0);
}
