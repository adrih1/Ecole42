# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahors <ahors@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 10:19:44 by ahors             #+#    #+#              #
#    Updated: 2024/02/23 16:41:15 by ahors            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./philo_test/srcs
SRCS =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/ft_errors.c \
		$(SRC_DIR)/ft_atoi.c \
	

$(NAME):
	$(CC) $(CFLAGS) -lm $(SRCS) -o $(NAME)

all: $(NAME)

clean:
		
fclean: clean
		/bin/rm -f philo

re: fclean all

.PHONY: all clean fclean re