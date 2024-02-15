# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahors <ahors@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 10:19:44 by ahors             #+#    #+#              #
#    Updated: 2024/02/15 18:12:46 by ahors            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./srcs
CC = cc
CFLAGS = -Wall -Wextra
FT_PRINTF = ft_printf/libftprintf.a

NAME_S = server
SERVER_SRC = $(SRC_DIR)/server.c

NAME_C = client
CLIENT_SRC = $(SRC_DIR)/client.c

all: $(NAME_S) $(NAME_C)

$(NAME_S):
	$(MAKE) -C ./ft_printf
	$(CC) $(CFLAGS) -lm $(SERVER_SRC) $(FT_PRINTF) -o $(NAME_S)

$(NAME_C):
	$(CC) $(CFLAGS) -lm $ $(CLIENT_SRC) $(FT_PRINTF) -o $(NAME_C) -g

bonus: $(NAME_S) $(NAME_C)

clean:
	$(MAKE) fclean -C ./ft_printf
	
fclean: clean
	/bin/rm -f $(NAME_S)
	/bin/rm -f $(NAME_C)

re: fclean all