NAME = libasm.a

ASM = nasm
ASMFLAGS = -f elf64
		
SRCS =	ft_read.s \
		ft_strcmp.s \
		ft_strcpy.s \
		ft_strdup.s \
		ft_strlen.s \
		ft_write.s \
		main.c

OBJS = $(SRCS:.s=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	gcc -no-pie -o $(NAME) $(OBJS)

%.o: %.s
	$(ASM) $(ASMFLAGS) $< -o $@

clean:
	$(RM) $(filter %.o,$(OBJS)) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
