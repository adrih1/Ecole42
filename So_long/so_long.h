#ifndef SO_LONG_H
# define SO_LONG_H
/*
---------------------------------------------------------------------------------
|                                    LIBRAIRIE                                  |
---------------------------------------------------------------------------------
*/


#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
/*
---------------------------------------------------------------------------------
|                                    STRUCTURES                                  |
---------------------------------------------------------------------------------
*/

// Structure pour l'interface graphique
typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
} t_data;

// Structure pour représenter la carte
typedef struct s_map
{
    int width;
    int height;
    char **grid;
} t_map;

// Structure pour stocker les informations de la carte
typedef struct s_map_info
{
    int start_count;
    int exit_count;
    int item_count;
    int player_row;
    int player_col;
} t_map_info;

/*
---------------------------------------------------------------------------------
|                                    FONCTIONS                                  |
---------------------------------------------------------------------------------
*/

// MAP VALIDATION
//Free
void ft_free_map(t_map *map);
//Walls
int ft_validate_columns(const t_map *map);
int ft_validate_rows(const t_map *map);
int ft_validate_walls(const t_map *map); 
// Start and Exit
int ft_check_exit(const char *line);
int ft_check_start(const char *line);


// FONCTIONS INTERFACE
void    *ft_load_image(void *mlx_ptr, char *file_path, int *width, int *height);
int     on_destroy(t_data *data);
int     on_keypress(int keysym, t_data *data);


#endif
