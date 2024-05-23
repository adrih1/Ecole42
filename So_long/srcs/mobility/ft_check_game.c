/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:46:49 by ahors             #+#    #+#             */
/*   Updated: 2024/05/23 17:22:38 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	g_keypress_count = 0;

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
	if(result != 0)	
	{
		g_keypress_count++;
		printf("Keypress Count: %d\n", g_keypress_count);
	}
	if (result == 3)
		on_destroy(map);
	return (result);
}
