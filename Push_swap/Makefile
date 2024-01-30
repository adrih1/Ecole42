# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahors <ahors@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 10:19:44 by ahors             #+#    #+#              #
#    Updated: 2024/01/30 14:49:24 by ahors            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a

SRC_DIR = ./srcs
SRC = $(SRC_DIR)/commands/*.c $(SRC_DIR)/push_swap_sources/*.c
SRCM = $(SRC) $(SRC_DIR)/main_push_swap.c

NAMEB = checker
SRCB_DIR = ./srcs_bonus
GNL_DIR = ./get_next_line
SRCB = $(SRC) srcs_bonus/checker.c

all: $(NAME)

$(NAME):
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -lm $(SRCM) $(LIBFT) -o $(NAME)

bonus:
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -lm $ $(SRCB) $(LIBFT) ./get_next_line/*.o -o $(NAMEB) -g

$(NAMEB): bonus

clean:
	$(MAKE) fclean -C ./libft
	$(MAKE) clean -C ./libft
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all