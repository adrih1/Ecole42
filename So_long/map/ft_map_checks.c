#include "../so_long.h"

void ft_check_exit(t_map *map)
{
    int i;
    int j;

    if (map == NULL)
        return;
    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            if (map->grid[i][j] == 'E')
                map->exit_count++;
            j++; 
        }
        i++;
    }
}


void ft_check_start(t_map *map)
{
    int i;
    int j;

    if (map == NULL)
        return;
    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            if (map->grid[i][j] == 'P')
                map->start_count++;
            j++; 
        }
        i++;
    }
}

void ft_check_items(t_map *map)
{
    int i;
    int j;

    if (map == NULL)
        return;
    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            if (map->grid[i][j] == 'C')
                map->item_count++;
            j++; 
        }
        i++;
    }
}

int ft_check_rectangular(t_map *map)
{
    unsigned long   i;
    unsigned long   len;

    i = 0;
    len = strlen(map->grid[i]);
    while ((int)i < map->height)
    {
        if (len != strlen(map->grid[i]) && ((int)i != map->height - 1))
            return 0;
        i++;
    }
    i--;
    if(len != strlen(map->grid[i]) + 1)
        return (0);
    return (1);
}