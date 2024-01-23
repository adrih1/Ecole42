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


void    ft_init_maps(t_map *map, t_map_info *map_info)
{
    map->width = 0;
    map->height = 0;
    map->grid = NULL;
    map_info->exit_count = 0;
    map_info->item_count = 0;
    map_info->start_count = 0;
}

int ft_check_map(int fd, char *filename)
{
    t_map *map;
    t_map_info *map_info;

    map = (t_map *)malloc(sizeof(t_map));
    if (map == NULL)
        return 0;
    map_info = (t_map_info *)malloc(sizeof(t_map_info));
    if (map_info == NULL) 
        return 0;
    ft_init_maps(map, map_info);
    ft_parse_map(map, fd, filename);
    ft_get_map_width(map);
    ft_check_exit(map, map_info);
    ft_check_start(map, map_info);
    ft_check_items(map, map_info);
    if(map_info->start_count > 1 || map_info->exit_count > 1 || map_info->item_count < 1 || !ft_validate_walls(map) || !ft_check_rectangular(map))
        return (0);
    return 1;
}

// #include <stddef.h>
// int	main(void)
// {
// 	char	*filename = "map.ber";
// 	int fd;

// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("Probleme pour pour ouvrir le fichier");
// 		return (1);
// 	}
//     printf("CHECK_MAP : %d\n", ft_check_map(fd, filename));


// 	close(fd);
// 	return (0);
// }