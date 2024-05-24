#include "../so_long.h"

static void	ft_flood_fill_util(t_map *map, int x, int y)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height
		|| map->visited[y][x] || map->grid[y][x] == '1')
		return ;
	map->visited[y][x] = true;
	if (map->grid[y][x] == 'C')
		map->item_count--;
	if (map->grid[y][x] == 'E')
		map->exit_found = true;
	ft_flood_fill_util(map, x + 1, y);
	ft_flood_fill_util(map, x - 1, y);
	ft_flood_fill_util(map, x, y + 1);
	ft_flood_fill_util(map, x, y - 1);
}

bool	ft_check_path_exists(t_map *map)
{
	// t_map data;
	int i;

	i = 0;
	// data.map = map;
	// map->exit_found = false;
	// map->item_count = itemsCount;
	map->visited = malloc(map->height * sizeof(bool *));
	while (i < map->height)
	{
		map->visited[i] = ft_calloc(map->width, sizeof(bool));
		i++;
	}
	ft_flood_fill_util(map, map->player_row, map->player_col);
	i = 0;
	while (i < map->height)
	{
		free(map->visited[i]);
		i++;
	}
	return (map->exit_found && map->item_count == 0);
}