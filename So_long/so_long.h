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
#include <fcntl.h>
#include "get_next_line/get_next_line.h"


// TESTING TO BE DELETED
#include <string.h>


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
int ft_check_map(int fd, char *filename);
//Free
void ft_free_map(t_map *map);
//Walls
int ft_validate_columns(t_map *map);
int ft_validate_rows(t_map *map);
int ft_validate_walls(t_map *map); 
// Start, Exit and Item
void ft_check_exit(t_map *map, t_map_info *map_info);
void ft_check_start(t_map *map, t_map_info *map_info);
void ft_check_items(t_map *map, t_map_info *map_info);
//Dimensions
void    ft_parse_map(t_map *map, int fd, char *filename);
void    ft_get_map_width(t_map *map);

// FONCTIONS INTERFACE
void    *ft_load_image(void *mlx_ptr, char *file_path, int *width, int *height);
int     on_destroy(t_data *data);
int     on_keypress(int keysym, t_data *data);



//Utils
void    ft_close_file(int fd);
int    ft_open_file(char *filename);
#endif
