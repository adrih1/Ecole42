#include "so_long.h"
#include <stddef.h>

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

int ft_check_exit(const char *line)
{
    size_t  j;
    size_t len; 
    
    
    len = ft_strlen(line);
    j=0; 
    while (j < len)
    {
        if (line[j] == 'E')
            return 1;
        j++;
    }

    return 0;
}

int ft_check_start(const char *line)
{
    size_t  j;
    size_t len; 
    
    
    len = ft_strlen(line);
    j=0; 
    while (j < len)
    {
        if (line[j] == 'P')
            return 1;
        j++;
    }

    return 0;
}




int ft_parse_map(const char *file, t_map *map, t_map_info *map_info)
{
    int i = 0;
    char *line;
    int map_width;
    int map_height; 

    // Récupèrer la height et width de la map (nombre de lignes et de colonnes)
    ft_get_map_width(file, map);
    ft_get_map_height(file, map);

    // Allouez l'espace pour map->grid
    map->grid = (char **)malloc(map->height * sizeof(char *));
    if (!map->grid)
        return 0;

    while (line = get_next_line(file) != NULL)
    {
        // Allouez l'espace pour chaque ligne
        map->grid[i] = strdup(line);
        if (!map->grid[i])
            return (0);
        // Check E et P
        if (ft_check_exit(map->grid[i]))
            map_info->exit_count++;
        if (ft_check_start(map->grid[i]))
            map_info->start_count++;
        free(line);
        i++;
    }

    // Ajoutez la logique pour vérifier qu'il y a exactement un P et un E
    if(map_info->start_count > 1 || map_info->exit_count > 1)
        return (0);
    // Ajoutez la logique pour vérifier les murs tout autour


    return 1; 
}
