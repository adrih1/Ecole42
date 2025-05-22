/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:48:34 by ahors             #+#    #+#             */
/*   Updated: 2023/12/12 13:37:29 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*ft_create_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_clean_buffer(char *buffer)
{
	char	*new_buffer;
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_calloc((ft_str_len(buffer) - i + 1), sizeof(char));
	i++;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	free(buffer);
	return (new_buffer);
}

char	*ft_read(int fd, char *buffer)
{
	char	*reading;
	int		byte_read;

	byte_read = 1;
	if (!buffer)
		buffer = ft_calloc(1, 1);
	reading = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (byte_read > 0)
	{
		byte_read = read(fd, reading, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(reading);
			return (NULL);
		}
		reading[byte_read] = 0;
		buffer = ft_join_free(buffer, reading);
		if (ft_line_end(buffer))
			break ;
	}
	free(reading);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE == 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_create_line(buffer);
	buffer = ft_clean_buffer(buffer);
	return (line);
}

// #include <fcntl.h>
// int	main(void)
// {
// 	const char	*filename = "text.txt";
// 	int fd;

// 	fd = open(filename, O_RDONLY);
// 	if (fd <0)
// 	{
// 		printf("Probleme pour pour ouvrir le fichier");
// 		return (1);
// 	}

// 	printf("%s", get_next_line((fd)));
// 	printf("%s", get_next_line((fd)));
// 	printf("%s", get_next_line((fd)));
// 	printf("%s", get_next_line((fd)));

// 	close(fd);
// 	return (0);
// }
