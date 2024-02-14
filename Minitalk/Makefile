# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahors <ahors@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 10:19:44 by ahors             #+#    #+#              #
#    Updated: 2024/02/14 16:30:14 by ahors            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CC = cc
CFLAGS = -Wall -Werror -Wextra
# LIBFT = libft/libft.a

SRC_DIR = ./srcs
SRC = 	$(SRC_DIR)/commands/main.c

all: $(NAME)

$(NAME):
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -lm $(SRCM) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) fclean -C ./libft
	$(MAKE) clean -C ./libft
	/bin/rm -f $(OBJ)
	

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all