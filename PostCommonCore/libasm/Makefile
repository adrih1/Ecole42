NAME        = libasm.a
AS          = nasm
ASFLAGS     = -f elf64
SRCS        = ft_strlen.s \
              ft_strcpy.s \
              ft_strcmp.s \
              ft_write.s  \
              ft_read.s   \
              ft_strdup.s

OBJS        = $(SRCS:.s=.o)
RM          = rm -f
AR          = ar rcs
GREEN       = \033[0;32m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: all
	cc -Wall -Werror -Wextra main.c test_ft_read.c -L. -lasm && ./a.out

.PHONY: all clean fclean re