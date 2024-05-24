/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:48:04 by ahors             #+#    #+#             */
/*   Updated: 2024/05/24 14:23:04 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_keypress(int keynum, t_map *map)
{
	if (keynum == 119 || keynum == 97 || keynum == 100 || keynum == 115)
		ft_get_player_coordinate(map, keynum);
	return (keynum);
}

int	on_destroy(t_map *map)
{
	ft_free_all(map);
	exit(0);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_map	*map;
	char	*filename;
	int		fd;

	(void)ac;
	filename = av[1];
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Probleme pour ouvrir le fichier\n");
		return (1);
	}
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		ft_free_all(map);
		exit(1);
	}
	if (ft_check_map(fd, filename, map) == 0)
	{
		ft_free_all(map);
		exit(1);
	}
	close(fd);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
	{
		free(data.mlx_ptr);
		return (1);
	}
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1250, 400, "Mon premier jeu !");
	if (!data.win_ptr)
	{
		free(data.win_ptr);
		return (1);
	}
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
