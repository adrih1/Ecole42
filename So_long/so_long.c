#include "so_long.h"

//Compteur Mouvements
int keypress_count = 0;

int on_keypress(t_data *data)
{
	(void)data;
    keypress_count++; 
	printf("Key Press Count: %d\n", keypress_count);
	return (0);
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
	void *img_ptr;
	int img_width = 30;
    int img_height = 10;

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
    ft_map_generate(map, data);
	close(fd);
    
	// Initialise la connexion avec le serveur graphique
    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
        return (1);

    data.win_ptr = mlx_new_window(data.mlx_ptr, 700, 400, "Mon premier jeu !");
    if (!data.win_ptr)
    {
        free(data.mlx_ptr);
        return (1);
    }

    img_ptr = ft_load_image(data.mlx_ptr, "assets/wall.xpm", &img_width, &img_height);
    if (!img_ptr)
    {
		on_destroy(&data);
		return(0);
    }

    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img_ptr, 0, 0);

    // Hooks touches appuyées et fermeture de la fenêtre
    mlx_hook(data.win_ptr, 2, 1L << 0, on_keypress, &data);
	mlx_hook(data.win_ptr, 17, 1L<<4, on_destroy, &data);

    // Boucle pour attendre des événements (fenêtre ouverte)
    mlx_loop(data.mlx_ptr);

	//Libère les ressources
    mlx_destroy_image(data.mlx_ptr, img_ptr);
   	on_destroy(&data);
    return (0);
}