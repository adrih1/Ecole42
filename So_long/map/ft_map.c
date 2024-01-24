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

int ft_check_map(int fd, char *filename, t_map *map)
{
    ft_init_map(map);
    ft_parse_map(map, fd, filename);
    ft_get_map_width(map);
    ft_check_exit(map);
    ft_check_start(map);
    ft_check_items(map);
    if(map->start_count > 1 || map->exit_count > 1 || map->item_count < 1 || !ft_validate_walls(map) || !ft_check_rectangular(map))
    {
        ft_free_map(map);
        //Afficher Erreur 
        return (0);
    }
    return (1);
}

void	ft_render_texture(t_data *data, char *filename, int img_width, int img_height)
{
	void *img_ptr;

	img_ptr = ft_load_image(data->mlx_ptr, filename, &img_width, &img_height);
    if (!img_ptr)
    {
		on_destroy(&data);
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, 0, 0);
}

void    ft_map_generate(t_map *map, t_data data)
{
    int i;
    int j;

    
    i = 0;
    j = 0;
    while(map->grid[i])
    {     
        j = 0;
        while(map->grid[i][j])
        {
            if(map->grid[i][j] == "0")
            {
                
            }
            if(map->grid[i][j] == "1")
                //Afficher texture mur 
            if(map->grid[i][j] == "C")
                //Afficher texture Item
            if(map->grid[i][j] == "P")
                //Definir map->player row et player colommn a lindex de grid 
            j++;
        }
        i++;
    }
}