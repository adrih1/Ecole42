/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_dimensions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:48:16 by ahors             #+#    #+#             */
/*   Updated: 2024/01/29 15:48:16 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_check_map_end(const char *line)
{
    int i;

    i = 0;
    while (line[i] != '\0')
    {
        if(line[i] == '\0')
            return(1);
        i++;
    }
    return(0);

}

void    ft_get_map_width(t_map *map)
{
    if(!map)
        ft_free_map(map);
    map->width = strlen(map->grid[0]);
}

void ft_parse_map(t_map *map, int fd, char *filename)
{
    int count;
    char *line;
    int i;

    count = 0; 
    while ((line = get_next_line(fd)) && line[0] != '\0')
    {
        count++;
        free(line);
    }
    map->height = count;
    map->grid = (char **)malloc(map->height * sizeof(char *));
    ft_close_file(fd);
    fd = ft_open_file(filename);
    i = 0;
    while ((line = get_next_line(fd)) && line[0] != '\0')
    {
        map->grid[i] = strdup(line);
        i++;
    }
    close(fd);
}