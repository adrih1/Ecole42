#include "so_long.h"


int on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\n", keysym);
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


// int	main(void)
// {
// 	t_data	data;


// 	data.mlx_ptr = mlx_init();
// 	data.win_ptr = mlx_new_window(data.mlx_ptr, 700, 400, "Hello world!");
// 	mlx_hook(data.win_ptr, 2, 1L<<0, on_keypress, &data);
// 	mlx_hook(data.win_ptr, 17, 1L<<4, on_destroy, &data);

// 	mlx_loop(data.mlx_ptr);
// 	return (0);
// }

int main(void)
{
    t_data data;

    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
        return (1);

    data.win_ptr = mlx_new_window(data.mlx_ptr, 700, 400, "Hello world!");
    if (!data.win_ptr)
    {
        free(data.mlx_ptr);
        return (1);
    }

    // Chargement de l'image
    int img_width, img_height;
    void *img_ptr = ft_load_image(data.mlx_ptr, "assets/Idle-Sheet-Wizard.xpm", &img_width, &img_height);
    if (!img_ptr)
    {
        mlx_destroy_window(data.mlx_ptr, data.win_ptr);
        free(data.mlx_ptr);
        return (1);
    }

    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img_ptr, 0, 0);

    // Hooks touches préssées et fermeture de la fenêtre
    mlx_hook(data.win_ptr, 2, 1L << 0, &on_keypress, &data);
	mlx_hook(data.win_ptr, 17, 1L<<4, on_destroy, &data);

    // Boucle pour attendre des événements (fenêtre ouverte)
    mlx_loop(data.mlx_ptr);

    // Libération des ressources
    mlx_destroy_image(data.mlx_ptr, img_ptr);
    mlx_destroy_window(data.mlx_ptr, data.win_ptr);
    free(data.mlx_ptr);

    return (0);
}