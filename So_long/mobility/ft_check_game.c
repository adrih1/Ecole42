/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:46:49 by ahors             #+#    #+#             */
/*   Updated: 2024/05/14 18:48:36 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_movement_possible(char c, t_map *map)
{
	if (c == 'C')
		map->item_count--;
	if (c == '1')
		return (0);
	if (map->item_count != 0 && c == 'E')
		return (0);
	if (map->item_count == 0 && c == 'E')
		return (3);
	return (1);
}

int	ft_move_game_finish(char c, t_map *map)
{
	int	result;

	result = ft_check_movement_possible(c, map);
	if (result == 3)
	{
		on_destroy(map);
	}
	return (result);
}
