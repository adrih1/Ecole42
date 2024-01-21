HEADER_DIR = ./mlx/
MLX_DIR = ./mlx/

SRCS =	so_long.c \
		ft_map.c \
		ft_map_dimensions.c \
		ft_map_walls.c \
		ft_map_checks.c \
		ft_utils.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c
	
OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -f

CFLAGS = -Wall -Wextra  -I$(HEADER_DIR)

MAKE_MLX = make -C $(MLX_DIR)
MLX_A = $(MLX_DIR)libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit


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
