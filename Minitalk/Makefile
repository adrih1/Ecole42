# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 10:19:44 by ahors             #+#    #+#              #
#    Updated: 2024/02/19 14:23:39 by adrienhors       ###   ########.fr        #
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
	$(CC) $(CFLAGS) -lm $ $(CLIENT_SRC) $(FT_PRINTF) -o $(NAME_C)


# Bonus
SRC_DIR_BONUS = ./srcs_bonus
NAME_S_BONUS = server_bonus
SERVER_SRC_BONUS = $(SRC_DIR_BONUS)/server_bonus.c

NAME_C_BONUS = client_bonus
CLIENT_SRC_BONUS = $(SRC_DIR_BONUS)/client_bonus.c

$(NAME_S_BONUS):
	$(MAKE) -C ./ft_printf
	$(CC) $(CFLAGS) -lm $(SERVER_SRC_BONUS) $(FT_PRINTF) -o $(NAME_S_BONUS)

$(NAME_C_BONUS):
	$(MAKE) -C ./ft_printf
	$(CC) $(CFLAGS) -lm $(CLIENT_SRC_BONUS) $(FT_PRINTF) -o $(NAME_C_BONUS)

bonus: $(NAME_S_BONUS) $(NAME_C_BONUS)

clean:
	$(MAKE) fclean -C ./ft_printf
	/bin/rm -f $(NAME_S)
	/bin/rm -f $(NAME_C)
	
fclean: clean
	/bin/rm -f $(NAME_S_BONUS)
	/bin/rm -f $(NAME_C_BONUS)

re: fclean all