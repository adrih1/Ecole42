# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahors <ahors@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 10:19:44 by ahors             #+#    #+#              #
#    Updated: 2024/02/20 16:57:46 by ahors            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a

SRC_DIR = ./srcs
SRC = 	$(SRC_DIR)/commands/push.c  \
		$(SRC_DIR)/commands/rev_rotate.c \
		$(SRC_DIR)/commands/rotate.c \
		$(SRC_DIR)/commands/swap.c \
 		$(SRC_DIR)/push_swap_sources/ft_atol.c \
		$(SRC_DIR)/push_swap_sources/ft_errors.c \
		$(SRC_DIR)/push_swap_sources/ft_find.c \
		$(SRC_DIR)/push_swap_sources/ft_init_nodes.c \
		$(SRC_DIR)/push_swap_sources/ft_init.c \
		$(SRC_DIR)/push_swap_sources/ft_rotate_rules.c \
		$(SRC_DIR)/push_swap_sources/ft_sort_stacks.c \
		$(SRC_DIR)/push_swap_sources/ft_sort_three.c \
		$(SRC_DIR)/push_swap_sources/ft_utils.c \
		
SRCM = $(SRC) $(SRC_DIR)/push_swap.c

NAMEB = checker
SRCB_DIR = ./srcs_bonus
GNL_DIR = ./get_next_line
SRCB = 	$(SRC) \
		$(SRCB_DIR)/checker.c \
		$(GNL_DIR)/get_next_line_bonus.c \
		$(GNL_DIR)/get_next_line_utils_bonus.c

all: $(NAME)

$(NAME):
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -lm $(SRCM) $(LIBFT) -o $(NAME)

$(NAMEB):
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -lm $ $(SRCB) $(LIBFT) -o $(NAMEB) -g

bonus: $(NAME) $(NAMEB)

clean:
	$(MAKE) fclean -C ./libft
	/bin/rm -f $(SRCB_DIR)/checker.o
	

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(NAMEB)

re: fclean all bonus

.PHONY: all clean fclean re bonus