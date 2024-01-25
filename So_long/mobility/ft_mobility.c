#include "../so_long.h"


// void    ft_check_movement_possible(t_data *data, t_map *map, int keynum)
// {

// }

// Explication du calcul 
void ft_get_player_coordinate(t_map *map, int keynum)
{
    int i;
    int j;

    i = 0;
    j = 0;
    // if W --> Player row - 1 
    if(keynum == 119)
    {
        // Position initiale de P
        map->grid[map->player_row / 32][map->player_col / 32] = '0';
        i = map->player_col / 32;
        j = ((map->player_row / 32) - 1);
        map->grid[j][i] = 'P'; 
        ft_map_generate(map, map->data);
    }

    // if S --> Player row + 1
    if(keynum == 100)
        map->player_row = ((map->player_row / 32) + 1) * 32; 


    // if A --> Play Col - 1
    if(keynum == 97)
        map->player_col = ((map->player_col / 32) - 1) * 32; 

    // if D --> Player Col + 1
    if(keynum == 115)
        map->player_col = ((map->player_col / 32) + 1) * 32;

    // ft_check_movement_possible(data, map, keynum); 
    
}
