
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
SRC_DIR = srcs
SRC = $(shell find $(SRC_DIR) -name '*.c')
OBJ = $(SRC:.c=.o)


NAMEBONUS= checker
SRC_BONUS_DIR = srcs_bonus
SRC_BONUS = $(shell find $(SRC_BONUS_DIR) -name '*.c')
OBJ_BONUS = $(SRC_BONUS:.c=.o)

RM = rm -f


all: $(NAME) $(NAMEBONUS)


$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)



bonus:$(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $(NAMEBONUS) $(OBJ_BONUS)


$(NAMEBONUS): bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re