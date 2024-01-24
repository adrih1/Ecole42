#include "../so_long.h"

void ft_free_map(t_map *map)
{
    int i;

    i = 0;
    while (i < map->height)
    {
        free(map->grid[i]);
        i++;
    }
    free(map->grid);
}


void    ft_init_map(t_map *map)
{
    map->width = 0;
    map->height = 0;
    map->grid = NULL;
    map->exit_count = 0;
    map->item_count = 0;
    map->start_count = 0;
}

int ft_check_map(int fd, char *filename)
{
    t_map *map;

    map = (t_map *)malloc(sizeof(t_map));
    if (map == NULL)
        return 0;
    ft_init_map(map);
    ft_parse_map(map, fd, filename);
    ft_get_map_width(map);
    ft_check_exit(map);
    ft_check_start(map);
    ft_check_items(map);
    if(map->start_count > 1 || map->exit_count > 1 || map->item_count < 1 || !ft_validate_walls(map) || !ft_check_rectangular(map))
        return (0);
    return 1;
}

void    ft_map_generate(t_map *map)
{

}