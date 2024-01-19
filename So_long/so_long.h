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
|                                    FONCTIONS                                  |
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


#endif
