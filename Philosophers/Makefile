# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 10:19:44 by ahors             #+#    #+#              #
#    Updated: 2024/04/15 15:34:02 by adrienhors       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./philo_test/srcs
SRCS =	$(SRC_DIR)/ft_atol.c \
		$(SRC_DIR)/ft_errors.c \
		$(SRC_DIR)/ft_getters_setters.c \
		$(SRC_DIR)/ft_init.c \
		$(SRC_DIR)/ft_parsing.c \
		$(SRC_DIR)/ft_protect.c \
		$(SRC_DIR)/ft_simu.c \
		$(SRC_DIR)/ft_synchro_utils.c \
		$(SRC_DIR)/ft_utils.c \
		$(SRC_DIR)/main.c \

	

$(NAME):
	$(CC) $(CFLAGS) -lm $(SRCS) -o $(NAME)

all: $(NAME)

clean:
		
fclean: clean
		/bin/rm -f philo

re: fclean all

.PHONY: all clean fclean re