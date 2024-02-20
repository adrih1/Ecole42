# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahors <ahors@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 10:19:44 by ahors             #+#    #+#              #
#    Updated: 2024/02/20 13:47:46 by ahors            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./srcs
CC = cc
CFLAGS = -Wall -Wextra

NAME = philo
SRC = $(SRC_DIR)/*.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -lm $(SERVER_SRC) -o $(NAME)

clean:
	/bin/rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re