# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahors <ahors@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 10:19:44 by ahors             #+#    #+#              #
#    Updated: 2024/02/14 17:21:11 by ahors            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CC = cc
CFLAGS = -Wall -Werror -Wextra
FT_PRINTF = ft_printf/libftprintf.a

SRC_DIR = ./srcs
SRC = 	$(SRC_DIR)/main.c \
		$(SRC_DIR)/client.c \
		$(SRC_DIR)/server.c

all: $(NAME)

$(NAME):
	$(MAKE) -C ./ft_printf
	$(CC) $(CFLAGS) -lm $(FT_PRINTF) -o $(NAME)

clean:
	$(MAKE) fclean -C ./ft_printf
	$(MAKE) clean -C ./ft_printf
	/bin/rm -f $(OBJ)
	

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all