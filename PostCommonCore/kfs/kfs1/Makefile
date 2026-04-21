NAME        = kfs.iso
BIN         = kfs.bin
CC          = gcc
SRC_DIR     = src
OBJ_DIR     = .obj
CFLAGS      = -m32 -std=gnu99 -ffreestanding -Wall -Wextra -Werror -nostdlib -fno-builtin -fno-exceptions -fno-stack-protector -nodefaultlibs -Iincludes
ASFLAGS     = -f elf32 

SRCS_C      = kernel.c terminal.c keymap.c tty.c
SRCS_S      = boot.s io.s

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS_C:.c=.o) $(SRCS_S:.s=.o))

CONTAINER_ENGINE = podman

RM          = rm -rf

all: $(NAME)

# C files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

#ASM files 
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	@mkdir -p $(OBJ_DIR)
	@nasm $(ASFLAGS) $< -o $@

# Create binary in obj for Dockerfile
$(BIN): $(OBJS)
	gcc -m32 -T $(SRC_DIR)/linker.ld -o $(OBJ_DIR)/$(BIN) -ffreestanding -nostdlib $(OBJS)

# ISO creation with Docker 
$(NAME): $(BIN)
	@$(CONTAINER_ENGINE) build -t iso_gen $(SRC_DIR)
	@$(CONTAINER_ENGINE) run --rm -v "$$(pwd)":/os:Z iso_gen

# Launch QEMU
boot: $(NAME)
	qemu-system-i386 -enable-kvm -cdrom $(NAME) 

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	$(CONTAINER_ENGINE) system prune -a --volumes -f

re: fclean all

.PHONY: all clean fclean re boot
