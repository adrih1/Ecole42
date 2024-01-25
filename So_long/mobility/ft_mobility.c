#include "../so_long.h"


int    ft_check_movement_possible(char c, t_map *map)
{
    if (c == 'C')
        map->item_count--;
    if (c == '1')
        return (0);
    printf("Item Count: %d\n", map->item_count);
    if (map->item_count != 0 && c == 'E')
        return (0);
    if(map->item_count == 0 && c == 'E')
        return(3);
    return (1);
}


int ft_check_game_finish(char c, t_map *map)
{
    int result = ft_check_movement_possible(c, map);  // Appel de ft_check_movement_possible

    if (result == 3)
    {
        free(map->data->mlx_ptr);
        // Autres actions à effectuer en cas de fin de jeu
    }

    // Autres conditions ou actions en fonction du résultat de ft_check_movement_possible

    return result;  // Vous pouvez également retourner le résultat pour une utilisation future si nécessaire
}

// Explication du calcul 
void ft_get_player_coordinate(t_map *map, int keynum)
{
    int i;
    int j;
    int new_i;
    int new_j;

    i = map->player_col / 32;
    j = map->player_row / 32;
    // if W --> Player row - 1
    if (keynum == 119)
    {
        new_i = i;
        new_j = j - 1;
        if (new_j >= 0 && ft_check_movement_possible(map->grid[new_j][new_i], map))
        {
            map->grid[j][i] = '0';
            map->grid[new_j][new_i] = 'P';
            map->player_row -= 32;
            ft_map_generate(map, map->data);
        }
    }

    // if S --> Player row + 1
    if(keynum == 115)
    {
        new_i = i;
        new_j = j + 1;
        if (new_j >= 0 && ft_check_movement_possible(map->grid[new_j][new_i], map))
        {
            map->grid[j][i] = '0';
            map->grid[new_j][new_i] = 'P';
            map->player_row += 32;
            ft_map_generate(map, map->data);
        }
    }

    // if A --> Play Col - 1
    if(keynum == 97)
    {
        new_i = i - 1;
        new_j = j;
        if (new_i >= 0 && ft_check_movement_possible(map->grid[new_j][new_i], map))
        {
            map->grid[j][i] = '0';
            map->grid[new_j][new_i] = 'P';
            map->player_col -= 32;
            ft_map_generate(map, map->data);
        }
    }

    // if D --> Player Col + 1
    if(keynum == 100)
    {
        new_i = i + 1;
        new_j = j;
        if (new_i >= 0 && ft_check_movement_possible(map->grid[new_j][new_i], map))
        {
            map->grid[j][i] = '0';
            map->grid[new_j][new_i] = 'P';
            map->player_col += 32;
            ft_map_generate(map, map->data);
        }
    }
}
