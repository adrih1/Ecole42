#include "so_long.h"

//Compteur Mouvements
int keypress_count = 0;

int on_keypress(int keynum, t_map *map)
{
    if(keynum == 119 || keynum == 97 || keynum == 100 || keynum == 115)
    {
        keypress_count++;
        printf("Keypress Count: %d\n", keypress_count);
    }
    ft_get_player_coordinate(map, keynum);
    return keynum;
}


int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

void *ft_load_image(void *mlx_ptr, char *file_path, int *width, int *height)
{
    void *img_ptr = mlx_xpm_file_to_image(mlx_ptr, file_path, width, height);
    if (!img_ptr)
        return NULL;
    return img_ptr;
}


int main(void)
{
    t_data data;
    t_map   *map;
    int pressed_key;
	// void *img_ptr;

	char	*filename = "map.ber";
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Probleme pour pour ouvrir le fichier");
		return (1);
	}
    map = (t_map *)malloc(sizeof(t_map));
    if (map == NULL)
        return 0;
    ft_check_map(fd, filename, map);
	close(fd);
    
	// Initialise la connexion avec le serveur graphique
    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
        return (1);

    data.win_ptr = mlx_new_window(data.mlx_ptr, 1000, 400, "Mon premier jeu !");
    if (!data.win_ptr)
    {
        free(data.mlx_ptr);
        return (1);
    }
    map->data = &data;
    map->data->random_num = 6;
    ft_map_generate(map, map->data);


    // Hooks touches appuyées et fermeture de la fenêtre
    mlx_hook(data.win_ptr, 2, 1L << 0, on_keypress, map);

    //Si W, S, A D appuyés 
        // Incremente Moove Count
        // ft_get_player_coordinate : Get Player Coordinate (map-> map->player_col et map->player_row)
            // if W --> Player row + 1 
            // if S --> Player row - 1
            // if A --> Play Col - 1
            // if D --> Player Col + 1
        // Check if Movement possible (conséquence des nouvelles coordonnées)
            //If same coordinate as collectable --> Re-render with character only
            //If same coordinate as wall --> Do not move (no re-render)
            //If valid coordinate 
                // Update Grid function : swap the character and floor coordinates
                // Ft_map generate 



     // Hooks fermeture de la fenêtre
	mlx_hook(data.win_ptr, 17, 1L<<4, on_destroy, &data);
  

    // Boucle pour attendre des événements (fenêtre ouverte)
    mlx_loop(data.mlx_ptr);

   	on_destroy(&data);
    return (0);
}