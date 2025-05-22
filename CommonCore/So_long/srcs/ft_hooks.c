/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:45:10 by ahors             #+#    #+#             */
/*   Updated: 2024/07/11 14:21:27 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_keypress(int keynum, t_map *map)
{
	if (keynum == 119 || keynum == 115 || keynum == 97 || keynum == 100)
		ft_get_player_coordinate(map, keynum);
	if (keynum == 65307)
		on_destroy(map);
	return (keynum);
}

int	on_destroy(t_map *map)
{
	ft_free_all(map);
	exit(0);
}
