#include "so_long.h"

void    ft_get_map_width(const char *file, t_map *map)
{
    char    *line; 

    line = get_next_line(file);
    if (line != NULL)
    {
        map->width = ft_strlen(line);
        free(line);
    }
    else
    {
        free(line);
    }

}

void ft_get_map_height(const char *file, t_map *map)
{
    int count;
    char *line;

    count = 0; 
    while ((line = get_next_line(file)) != NULL)
    {
        count++;
        free(line);
    }

    map->height = count;
}