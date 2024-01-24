#ifndef SO_LONG_H
# define SO_LONG_H
/*
---------------------------------------------------------------------------------
|                                    LIBRAIRIE                                  |
---------------------------------------------------------------------------------
*/

# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

// TESTING TO BE DELETED
# include <string.h>

/*
---------------------------------------------------------------------------------
|                                    STRUCTURES                                  |
---------------------------------------------------------------------------------
*/

// Structure pour l'interface graphique
typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_data;

// Structure pour représenter la carte
typedef struct s_map
{
	int		width;
	int		height;
	char	**grid;
	int		start_count;
	int		exit_count;
	int		item_count;
	int		player_row;
	int		player_col;
}			t_map;

/*
---------------------------------------------------------------------------------
|                                    FONCTIONS                                  |
---------------------------------------------------------------------------------
*/

// MAP VALIDATION
int			ft_check_map(int fd, char *filename, t_map *map);
// Free
void		ft_free_map(t_map *map);
// Init Map
void		ft_init_map(t_map *map);
// Walls
int			ft_validate_columns(t_map *map);
int			ft_validate_rows(t_map *map);
int			ft_validate_walls(t_map *map);
// Start, Exit, Item and Rectangular
void		ft_check_exit(t_map *map);
void		ft_check_start(t_map *map);
void		ft_check_items(t_map *map);
int			ft_check_rectangular(t_map *map);
// Dimensions
void		ft_parse_map(t_map *map, int fd, char *filename);
void		ft_get_map_width(t_map *map);
// Genarate Textures
void    ft_map_generate(t_map *map, t_data data);


// FONCTIONS INTERFACE

//Render Texture 
void	ft_render_texture(t_map *map, t_data data, char *filename, int img_width, int img_height, int j, int i);
void		*ft_load_image(void *mlx_ptr, char *file_path, int *width, int *height);
int			on_destroy(t_data *data);
int			on_keypress(int keynum, t_data *data);

// Utils
void		ft_close_file(int fd);
int			ft_open_file(char *filename);
#endif
