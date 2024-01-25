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


int ft_move_game_finish(char c, t_map *map)
{
    int result = ft_check_movement_possible(c, map);

    if (result == 3)
    {
        on_destroy(map->data);
    }
    return result;
}

void ft_move_up(t_map *map, int i, int j)
{
    int new_i = i;
    int new_j = j - 1;
    
    if (new_j >= 0 && ft_move_game_finish(map->grid[new_j][new_i], map))
    {
        map->grid[j][i] = '0';
        map->grid[new_j][new_i] = 'P';
        map->player_row -= 32;
        ft_map_generate(map, map->data);
    }
}

void ft_move_down(t_map *map, int i, int j)
{
    int new_i = i;
    int new_j = j + 1;

    if (new_j >= 0 && ft_move_game_finish(map->grid[new_j][new_i], map))
    {
        map->grid[j][i] = '0';
        map->grid[new_j][new_i] = 'P';
        map->player_row += 32;
        ft_map_generate(map, map->data);
    }
}

void ft_move_left(t_map *map, int i, int j)
{
    int new_i = i - 1;
    int new_j = j;

    if (new_i >= 0 && ft_move_game_finish(map->grid[new_j][new_i], map))
    {
        map->grid[j][i] = '0';
        map->grid[new_j][new_i] = 'P';
        map->player_col -= 32;
        ft_map_generate(map, map->data);
    }
}

void ft_move_right(t_map *map, int i, int j)
{
    int new_i = i + 1;
    int new_j = j;

    if (new_i >= 0 && ft_move_game_finish(map->grid[new_j][new_i], map))
    {
        map->grid[j][i] = '0';
        map->grid[new_j][new_i] = 'P';
        map->player_col += 32;
        ft_map_generate(map, map->data);
    }
}

// Explication du calcul 
void ft_get_player_coordinate(t_map *map, int keynum)
{
    int i;
    int j;

    i = map->player_col / 32;
    j = map->player_row / 32;
    if (keynum == 119) // W
        ft_move_up(map, i, j);

    if (keynum == 115) // S
        ft_move_down(map, i, j);

    if (keynum == 97)  // A
        ft_move_left(map, i, j);

    if (keynum == 100) // D
        ft_move_right(map, i, j);
}