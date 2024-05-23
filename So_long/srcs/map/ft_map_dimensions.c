/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_dimensions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:48:16 by ahors             #+#    #+#             */
/*   Updated: 2024/05/14 18:41:37 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_map_end(const char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

void	ft_get_map_width(t_map *map)
{
	if (!map)
		ft_free_all(map);
	map->width = strlen(map->grid[0]);
}

int	ft_find_map_height(int fd)
{
	char	*line;
	char	*temp;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line && line[0] != '\0')
	{
		temp = line;
		line = get_next_line(fd);
		free(temp);
		count++;
	}
	return (count);
}

void	ft_parse_line(t_map *map, int fd)
{
	int		i;
	char	*line;
	char	*temp;

	i = 0;
	line = get_next_line(fd);
	while (line && line[0] != '\0')
	{
		temp = line;
		map->grid[i] = strdup(line);
		line = get_next_line(fd);
		free(temp);
		i++;
	}
	free(line);
	close(fd);
}

void	ft_parse_map(t_map *map, int fd, char *filename)
{
	map->height = ft_find_map_height(fd);
	map->grid = (char **)malloc(map->height * sizeof(char *));
	if (!(map->grid))
		ft_free_all(map);
	ft_close_file(fd);
	fd = ft_open_file(filename);
	if (fd == 1)
		ft_free_all(map);
	ft_parse_line(map, fd);
}