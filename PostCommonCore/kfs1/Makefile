NAME        = kfs.bin

# COMPILERS
CC          = gcc
AS          = nasm
LD          = ld

# FLAGS
# -m32 : 32 bits code 
# -fno-builtin : No use of libc functions
# -nostdlib -nodefaultlibs : Start from zero, no standard library
CFLAGS      = -m32 -fno-builtin -fno-stack-protector \
            -nostdlib -nodefaultlibs -Wall -Wextra -Werror

# Assembly flags (format ELF 32 bits)
ASFLAGS     = -f elf32

# Linker
# -T linker.ld : Utilise notre script de lien personnalisé
LDFLAGS     = -m elf_i386 -T linker.ld


# FILES
SRCS_ASM    = boot.s
SRCS_C      = kernel.c

OBJS        = $(SRCS_ASM:.s=.o) $(SRCS_C:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Une règle pratique pour tester rapidement
test: all
	qemu-system-i386 -kernel $(NAME)

.PHONY: all clean fclean re test


