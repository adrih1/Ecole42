NAME = push_swap
CC = gcc -g
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SRCS = 	commands/push.c \
		commands/rev_rotate.c \
		commands/rotate.c \
		commands/swap.c \
       	push_swap_sources/ft_atoi.c \
		push_swap_sources/ft_errors.c \
		push_swap_sources/ft_find.c \
		push_swap_sources/ft_init_nodes.c \
		push_swap_sources/ft_init.c \
		push_swap_sources/ft_rotate_rules.c \
		push_swap_sources/ft_sort_stacks.c \
		push_swap_sources/ft_sort_three.c \
		push_swap_sources/ft_split.c \
		push_swap_sources/ft_utils.c \
		push_swap_sources/push_swap.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re