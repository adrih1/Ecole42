# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahors <ahors@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 10:19:44 by ahors             #+#    #+#              #
#    Updated: 2024/02/23 15:38:04 by ahors            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
FT_PRINTF = ft_printf/libftprintf.a

SRC_DIR = ./philo_test/srcs
SRCS =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/ft_errors.c \

$(NAME):
	$(MAKE) -C ./ft_printf
	$(CC) $(CFLAGS) -lm $(SRCS) $(FT_PRINTF) -o $(NAME)

all: $(NAME)

clean:
	$(MAKE) fclean -C ./ft_printf
	
fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re