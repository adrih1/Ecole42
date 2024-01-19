#include "so_long.h"


int on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\n", keysym);
	return (0);
}

int	close(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 700, 400, "Hello world!");
	mlx_hook(data.win_ptr, 2, 1L<<0, on_keypress, &data);
	mlx_hook(data.win_ptr, 17, 1L<<4, close, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}