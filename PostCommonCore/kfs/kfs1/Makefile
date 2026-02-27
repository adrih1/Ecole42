NAME        = kfs.bin
ISO         = kfs.iso

# Chemins
SRCDIR      = src
INCDIR      = includes
OBJDIR      = objs
ISODIR      = isodir

# Liste des fichiers
SRC_C       = kernel.c terminal.c keymap.c tty.c
SRC_S       = boot.s io.s
OBJS        = $(addprefix $(OBJDIR)/, $(SRC_C:.c=.o) $(SRC_S:.s=.o))

# Compilateurs & Linker
CC          = gcc
AS          = nasm
LD          = ld

# Flags
# -m32 : architecture x86 32 bits
# -fno-builtin : évite l'optimisation avec des fonctions libc que nous n'avons pas
# -fno-stack-protector : on gère nous-même la pile, pas besoin de canaris
CFLAGS      = -m32 -fno-builtin -fno-stack-protector -nostdlib -nodefaultlibs \
              -Wall -Wextra -Werror -I$(INCDIR)

ASFLAGS     = -f elf32

# -T linker.ld : utilise ton script de lien pour organiser les sections
LDFLAGS     = -m elf_i386 -T linker.ld

all: $(NAME)

# Lien du binaire (Le cœur du kernel)
$(NAME): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(NAME)
	@echo "Lien terminé : $(NAME)"

# Création de l'ISO (Le packaging)
$(ISO): $(NAME)
	@mkdir -p $(ISODIR)/boot/grub
	@cp $(NAME) $(ISODIR)/boot/$(NAME)
	@echo 'menuentry "kfs" {' > $(ISODIR)/boot/grub/grub.cfg
	@echo '    multiboot /boot/$(NAME)' >> $(ISODIR)/boot/grub/grub.cfg
	@echo '}' >> $(ISODIR)/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO) $(ISODIR)
	@echo "ISO créée : $(ISO)"

# Compilation des fichiers C
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation des fichiers ASM
$(OBJDIR)/%.o: $(SRCDIR)/%.s
	@mkdir -p $(OBJDIR)
	$(AS) $(ASFLAGS) $< -o $@

# --- RÈGLES DE TEST ---

# TEST RAPIDE : Charge le binaire directement (Direct Multiboot Boot)
test: $(NAME)
	qemu-system-i386 -kernel $(NAME)

# TEST RÉALISTE : Simule un CD-ROM avec GRUB (Full Boot Sequence)
iso: $(ISO)
	qemu-system-i386 -cdrom $(ISO)

# --- NETTOYAGE ---

clean:
	rm -rf $(OBJDIR) $(ISODIR)
	@echo "Objets et isodir nettoyés."

fclean: clean
	rm -f $(NAME) $(ISO)
	@echo "Binaire et ISO supprimés."

re: fclean all

.PHONY: all clean fclean re test test_iso