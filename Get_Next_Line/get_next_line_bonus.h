/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:51:17 by ahors             #+#    #+#             */
/*   Updated: 2023/12/12 13:20:51 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
/*
---------------------------------------------------------------------------------
|                                    LIBRAIRIE                                  |
---------------------------------------------------------------------------------
*/

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

/*
---------------------------------------------------------------------------------
|                                    FONCTIONS                                  |
---------------------------------------------------------------------------------
*/

size_t	ft_str_len(char *str);
size_t	ft_line_end(char *str);
void	*ft_memset(void *pointer, int value, size_t count);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_join_free(char *buffer, char *buf);
char	*ft_create_line(char *buffer);
char	*ft_clean_stash(char *buffer);
char	*ft_read(int fd, char *buffer);
char	*get_next_line(int fd);

#endif
