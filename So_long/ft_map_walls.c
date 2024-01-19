#include "so_long.h"

int ft_validate_columns(const t_map *map)
{
    int i = 0;

    // Première colonne
    while (i < map->height)
    {
        if (map->grid[i][0] != '1')
            return 0;
        i++;
    }

    // Dernière colonne
    i = 0;
    while (i < map->height)
    {
        if (map->grid[i][map->width - 1] != '1')
            return 0;
        i++;
    }

    return (1);
}

int ft_validate_rows(const t_map *map)
{
    int i = 0;

    // Première ligne
    while (i < map->width)
    {
        if (map->grid[0][i] != '1')
            return 0;
        i++;
    }

    // Dernière ligne
    i = 0;
    while (i < map->width)
    {
        if (map->grid[map->height - 1][i] != '1')
            return 0;
        i++;
    }

    return (1);
}

int ft_validate_walls(const t_map *map)
{
    if (ft_validate_columns(map) && ft_validate_rows(map))
        return (1);
    return (0);
}
