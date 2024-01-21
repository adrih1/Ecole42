#include "so_long.h"

void ft_check_exit(t_map *map, t_map_info *map_info)
{
    int i;
    int j;

    i = 0;
    while (map->grid[i])
    { 
        j = 0;
        while(map->grid[i][j])
        {
            if(map->grid[i][j] == 'E')
                map_info->exit_count++;
            j++;
        }
        i++;
    }
}

void ft_check_start(t_map *map, t_map_info *map_info)
{
    int i;
    int j;

    i = 0;
    while (map->grid[i])
    { 
        j = 0;
        while(map->grid[i][j])
        {
            if(map->grid[i][j] == 'P')
                map_info->start_count++;
            j++;
        }
        i++;
    }
}

void ft_check_items(t_map *map, t_map_info *map_info)
{
    int i;
    int j;

    i = 0;
    while (map->grid[i])
    { 
        j = 0;
        while(map->grid[i][j])
        {
            if(map->grid[i][j] == 'C')
                map_info->item_count++;
            j++;
        }
        i++;
    }
}
