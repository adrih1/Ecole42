#include "../so_long.h"

static void	ft_flood_fill_util(t_map *map, int x, int y)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height
		|| map->visited[y][x] || map->grid[y][x] == '1')
		{
			printf("On est la dans le if du flood fill\n");
			return ;
		}
	map->visited[y][x] = true;
	if (map->grid[y][x] == 'C')
	{
		printf("Map Item Count; %d\n", map->item_count);
		map->item_count--;
	}	
	if (map->grid[y][x] == 'E')
		map->exit_found = true;
	ft_flood_fill_util(map, x + 1, y);
	ft_flood_fill_util(map, x - 1, y);
	ft_flood_fill_util(map, x, y + 1);
	ft_flood_fill_util(map, x, y - 1);
}

bool	ft_check_path_exists(t_map *map)
{
	int i;

	i = 0;
	map->visited = (bool **)malloc(map->height * sizeof(bool *));
	if(!(map->visited))
		ft_free_all(map);
	while (i < map->height)
	{
		map->visited[i] = ft_calloc(map->width, sizeof(bool));
		i++;
	}
	printf("Player Row: %d\nPlayer Col: %d\n", map->player_row, map->player_col);
	ft_flood_fill_util(map, map->player_row, map->player_col);
	return (map->exit_found && (map->item_count == 0));
}