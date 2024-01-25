HEADER_DIR = ./mlx/
MLX_MAC_DIR = ./mlx-mac/
MLX_LINUX_DIR = ./mlx-linux/

SRCS = so_long.c \
    map/ft_map.c \
    map/ft_map_dimensions.c \
    map/ft_map_walls.c \
    map/ft_map_checks.c \
    ft_utils.c \
    get_next_line/get_next_line.c \
    get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -f

CFLAGS = -Wall -Wextra -I$(HEADER_DIR)

ifeq ($(shell uname -s),Darwin)
    MLX_DIR = $(MLX_MAC_DIR)
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
    MLX_DIR = $(MLX_LINUX_DIR)
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
endif

MLX_A = $(MLX_DIR)libmlx.a
MAKE_MLX = make -C $(MLX_DIR)

NAME = so_long

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	

$(NAME): $(OBJS)
	$(MAKE_MLX)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_A) $(MLX_FLAGS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE_MLX) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE_MLX) clean

re: fclean all

.PHONY: all clean fclean re
