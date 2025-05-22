NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SOURCES = ft_printf.c ft_putchar.c ft_putstr.c  ft_putnbr.c ft_putnbr_base_unsigned.c ft_putpointer.c ft_base_len.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJECTS)
		$(AR) $@ $^

clean:
	$(RM) ft_*.o

fclean: clean 
	$(RM) $(NAME)		

re: fclean all

.PHONY: all clean fclean re
