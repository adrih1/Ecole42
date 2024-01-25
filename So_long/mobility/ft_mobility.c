#include "../so_long.h"

// Explication du calcul 
void ft_get_player_coordinate(t_data *data, t_map *map, int keynum)
{
    // if W --> Player row - 1 
    if(keynum == 119)
        map->player_row = ((map->player_row / 32) - 1) * 32; 

    // if S --> Player row + 1
    if(keynum == 100)
        map->player_row = ((map->player_row / 32) + 1) * 32; 


    // if A --> Play Col - 1
    if(keynum == 97)
        map->player_col = ((map->player_col / 32) - 1) * 32; 

    // if D --> Player Col + 1
    if(keynum == 115)
        map->player_col = ((map->player_col / 32) + 1) * 32;

    ft_check_movement_possible(data, map, keynum); 
    
}

void    ft_check_movement_possible(t_data *data, t_map *map, int keynum)
{

}