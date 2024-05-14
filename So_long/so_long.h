#ifndef SO_LONG_H
# define SO_LONG_H
/*
---------------------------------------------------------------------------------
|                                    LIBRAIRIE                                  |
---------------------------------------------------------------------------------
*/

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
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
	int		random_num;
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
	void	*wall;
	void	*exit;
	void	*floor;
	void	*player;
	void	*collectable;
	t_data	*data;
	int		texture_width;
	int		texture_height;
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
void		ft_map_generate(t_map *map, t_data *data);

// FONCTIONS INTERFACE || GAME

// Render Texture
void		*ft_load_image(void *mlx_ptr, char *file_path, int *width, int *height);
void		ft_render_texture(t_data data, char *filename, int img_width, int img_height, int j, int i);

// New Version of Render
void 		ft_put_textures(t_data *data, t_map *map);
void		ft_load_textures1(t_map *map, t_data *data);
void		ft_load_textures2(t_map *map, t_data *data);
void		ft_load_first_layer(t_data *data, t_map *map);
void		ft_load_second_layer(t_data *data, t_map *map);
void		ft_load_third_layer(t_data *data, t_map *map);
void		ft_free_textures(t_data *data, t_map *map);

// Hooks
int			on_destroy(t_map *map);
int			on_keypress(int keynum, t_map *map);

// Mobility
void		ft_get_player_coordinate(t_map *map, int keynum);

// Utils
void		ft_close_file(int fd);
int			ft_open_file(char *filename);

// Cleaning
void ft_free_all(t_map *map);

#endif
