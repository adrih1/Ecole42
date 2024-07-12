/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:48:19 by ahors             #+#    #+#             */
/*   Updated: 2024/07/11 14:46:25 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_exit(t_map *map)
{
	int	i;
	int	j;

	if (map == NULL)
		return ;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->grid[i][j] && j < map->width)
		{
			if (map->grid[i][j] == 'E')
				map->exit_count++;
			j++;
		}
		i++;
	}
}

void	ft_check_items(t_map *map)
{
	int	i;
	int	j;

	if (map == NULL)
		return ;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->grid[i][j] && j < map->width)
		{
			if (map->grid[i][j] == 'C')
			{
				map->item_count++;
				map->item_count_flood_fill++;
			}
			j++;
		}
		i++;
	}
}

void	ft_check_player(t_map *map)
{
	int	i;
	int	j;

	if (map == NULL)
		return ;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->grid[i][j] && j < map->width)
		{
			if (map->grid[i][j] == 'P')
			{
				map->start_count++;
				map->player_col = j;
				map->player_row = i;
			}
			j++;
		}
		i++;
	}
}

int	ft_check_rectangular(t_map *map)
{
	unsigned long	i;
	unsigned long	len;

	i = 0;
	len = ft_str_len(map->grid[i]);
	while ((int)i < map->height - 1)
	{
		if (len != ft_str_len(map->grid[i]))
			return (0);
		i++;
	}
	if (len != (ft_str_len(map->grid[i]) + 1))
		return (0);
	return (1);
}
