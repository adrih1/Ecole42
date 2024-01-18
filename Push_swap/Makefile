NAME = checker
NAME2 = push_swap
CC = gcc -g
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

PUSHSWAPFD = push_swap/
CHECKERFD = checker/
COMMONFD = common/

SRCSFD = srcs/

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

SRC_CHECKER = checker/checker.c

OBJS = $(SRCS:.c=.o)
OBJS_CHECKER = $(SRC_CHECKER:.c=.o)

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