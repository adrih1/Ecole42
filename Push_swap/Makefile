NAME = push_swap
CC = gcc -g
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SRCS = 	commands/push.c \
		commands/rev_rotate.c \
		commands/rotate.c \
		commands/swap.c \
       	push_swap_sources/ft_atol.c \
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

SRCS_BONUS= bonus/

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = 

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJS) $(OBJS_BONUS)
	$(AR) $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re