NAME        = woody_woodpacker

# Compilateur et Flags
CC          = cc
NASM		= nasm 
NASM_FLAGS	= -f bin
# Add -I $(INCDIR) to say to compiler where to find woody.h 
CFLAGS      = -Wall -Wextra -Werror -g -I $(INCDIR)

# Directories
SRCDIR      = src/
INCDIR      = inc/
OBJDIR      = obj/

# Source files
SRC_FILES   = main.c \
              utils.c \
              elf_parser.c \
              elf_patcher.c \
              injector.c \
              create_file.c \
			  payload.c \
			  crypto.c

SRCS        = $(addprefix $(SRCDIR), $(SRC_FILES))
OBJS        = $(addprefix $(OBJDIR), $(SRC_FILES:.c=.o))

# Colors for terminal
GREEN       = \033[0;32m
RED         = \033[0;31m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)[SUCCESS]$(RESET) $(NAME) created."

# Generate payload from assembler
$(SRCDIR)payload.c: $(SRCDIR)payload.s
	@echo "$(GREEN)[BUILD]$(RESET) Compiling Assembly to raw binary..."
	@$(NASM) $(NASM_FLAGS) $< -o payload.bin
	@echo "$(GREEN)[BUILD]$(RESET) Converting binary to C array..."
	@xxd -i payload.bin > $@
	@# xxd nomme le tableau "payload_bin", on le renomme en "g_shellcode" avec sed
	@sed -i 's/unsigned char payload_bin/const unsigned char g_shellcode/g' $@
	@sed -i 's/unsigned int payload_bin_len/const size_t g_shellcode_size/g' $@
	@# On ajoute l'include de woody.h en haut du fichier pour avoir les types
	@sed -i '1i #include "woody.h"' $@
	@rm -f payload.bin
	@echo "$(GREEN)[SUCCESS]$(RESET) payload.c generated automatically."

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(SRCDIR)payload.c
	@rm -rf $(OBJDIR)
	@echo "$(RED)[CLEAN]$(RESET) Object directory removed."

fclean: clean
	@rm -f $(NAME)
	@rm -rf woody
	@rm -rf a.out
	@echo "$(RED)[FCLEAN]$(RESET) Binary removed."


re: fclean all

.PHONY: all clean fclean re
