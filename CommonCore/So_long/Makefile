NAME = so_long

CC = cc -g
RM = rm -f

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
HEADER_DIR = mlx/
MLX_DIR = mlx/

SRCS = 	get_next_line/get_next_line_utils.c \
		get_next_line/get_next_line.c \
		srcs/so_long.c \
		srcs/ft_hooks.c \
		srcs/ft_utils.c \
		srcs/ft_clean.c \
		srcs/map/ft_map.c \
		srcs/map/ft_check_route.c \
		srcs/map/ft_map_dimensions.c \
		srcs/map/ft_map_walls.c \
		srcs/map/ft_map_checks.c \
		srcs/map/ft_map_check_unknown_chars.c \
		srcs/map/map_render/ft_layer.c \
		srcs/map/map_render/ft_textures.c \
		srcs/mobility/ft_mobility.c \
		srcs/mobility/ft_check_game.c \



OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra  -I$(HEADER_DIR)
MAKE_MLX = make -C $(MLX_DIR)
MLX_A = $(MLX_DIR)libmlx.a


UNAME := $(shell uname)

ifeq ($(UNAME), Darwin) 
   INCLUDES = -I./includes -I./libft -I./ft_printf -I./mlx
   MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
    INCLUDES = -I./includes -I./libft -I./ft_printf -I./mlx
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
endif


all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(MAKE_MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX_A) $(MLX_FLAGS) -lm -o $(NAME)


$(LIBFT):
	make -C ./libft

$(PRINTF):
	make -C ./ft_printf

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS)
	make -C ./libft clean
	make -C ./ft_printf clean

fclean: clean
	$(RM) $(NAME)
	make -C ./libft clean
	make -C ./ft_printf clean
	$(MAKE_MLX) clean

re: fclean all

.PHONY: all clean fclean re