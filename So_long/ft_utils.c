#include "so_long.h"

void    ft_close_file(int fd)
{
    close(fd);
}

int    ft_open_file(char *filename)
{
    int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Probleme pour pour ouvrir le fichier");
		return (1);
	}
	return (fd);
}