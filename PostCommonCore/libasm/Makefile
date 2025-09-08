NAME = hello

ASM = nasm
ASMFLAGS = -f elf64

SRCS = ft_strlen.s main.s
OBJS = $(SRCS:.s=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ld -o $(NAME) $(OBJS)

%.o: %.s
	$(ASM) $(ASMFLAGS) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
