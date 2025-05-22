# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahors <ahors@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 10:19:44 by ahors             #+#    #+#              #
#    Updated: 2024/09/09 10:47:25 by ahors            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./philo_srcs/srcs
SRCS =	$(SRC_DIR)/ft_atol.c \
		$(SRC_DIR)/ft_clean.c \
		$(SRC_DIR)/ft_display.c \
		$(SRC_DIR)/ft_errors.c \
		$(SRC_DIR)/ft_init.c \
		$(SRC_DIR)/ft_monitor.c \
		$(SRC_DIR)/ft_parsing.c \
		$(SRC_DIR)/ft_simu.c \
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