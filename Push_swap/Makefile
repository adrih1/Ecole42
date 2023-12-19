NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SOURCES =

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
