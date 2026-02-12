NAME        = kfs.bin

# Chemins
SRCDIR      = src
INCDIR      = includes
OBJDIR      = objs

# Liste des fichiers
SRC_C       = kernel.c terminal.c
SRC_S       = boot.s io.s
OBJS        = $(addprefix $(OBJDIR)/, $(SRC_C:.c=.o) $(SRC_S:.s=.o))

# Compilateurs & Linker
CC          = gcc
AS          = nasm
LD          = ld

# Flags
# -m32 : architecture x86 32 bits
# -fno-builtin : évite l'optimisation avec des fonctions libc que nous n'avons pas
# -I$(INCDIR) : pour trouver tes headers
CFLAGS      = -m32 -fno-builtin -fno-stack-protector -nostdlib -nodefaultlibs \
              -Wall -Wextra -Werror -I$(INCDIR)

ASFLAGS     = -f elf32

# -T linker.ld : utilise ton script de lien pour organiser les sections
LDFLAGS     = -m elf_i386 -T linker.ld

all: $(NAME)

# Lien final des objets pour créer le binaire du Kernel
$(NAME): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(NAME)
	@echo "Lien terminé : $(NAME)"

# Compilation des fichiers C
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation des fichiers ASM
$(OBJDIR)/%.o: $(SRCDIR)/%.s
	@mkdir -p $(OBJDIR)
	$(AS) $(ASFLAGS) $< -o $@

# Test direct avec QEMU (pas besoin d'ISO ici)
test: $(NAME)
	qemu-system-i386 -kernel $(NAME)

clean:
	rm -rf $(OBJDIR)
	@echo "Objets nettoyés."

fclean: clean
	rm -f $(NAME)
	@echo "Binaire supprimé."

re: fclean all

.PHONY: all clean fclean re test