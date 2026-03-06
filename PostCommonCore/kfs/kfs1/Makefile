NAME        = kfs.bin
ISO         = kfs.iso

# Paths
SRCDIR      = src
INCDIR      = includes
OBJDIR      = objs
ISODIR      = isodir

# File list (N'oublie pas d'ajouter gdt.c et gdt_load.s ici quand tu les créeras)
SRC_C       = kernel.c terminal.c keymap.c tty.c
SRC_S       = boot.s io.s
OBJS        = $(addprefix $(OBJDIR)/, $(SRC_C:.c=.o) $(SRC_S:.s=.o))

# Compilers & Linker
CC          = gcc
AS          = nasm
LD          = ld

# Flags
# -ffreestanding : indispensable pour ne pas dépendre de la libc hôte
CFLAGS      = -m32 -fno-builtin -fno-stack-protector -nostdlib -nodefaultlibs \
              -ffreestanding -Wall -Wextra -Werror -I$(INCDIR)

ASFLAGS     = -f elf32
LDFLAGS     = -m elf_i386 -T linker.ld

all: $(NAME)

# Lien du binaire kernel
$(NAME): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(NAME)
	@echo "Lien terminé : $(NAME)"

# Création de l'ISO (Règle unique et propre)
$(ISO): $(NAME)
	@mkdir -p $(ISODIR)/boot/grub
	@cp $(NAME) $(ISODIR)/boot/$(NAME)
	@echo 'set timeout=0' > $(ISODIR)/boot/grub/grub.cfg
	@echo 'set default=0' >> $(ISODIR)/boot/grub/grub.cfg
	@echo 'menuentry "kfs" {' >> $(ISODIR)/boot/grub/grub.cfg
	@echo '    multiboot /boot/$(NAME)' >> $(ISODIR)/boot/grub/grub.cfg
	@echo '    boot' >> $(ISODIR)/boot/grub/grub.cfg
	@echo '}' >> $(ISODIR)/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO) $(ISODIR)
	@echo "ISO créée : $(ISO)"

# Compilation C
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation ASM
$(OBJDIR)/%.o: $(SRCDIR)/%.s
	@mkdir -p $(OBJDIR)
	$(AS) $(ASFLAGS) $< -o $@

# TEST Rapide : Charge le binaire directement (sans ISO)
test: $(NAME)
	qemu-system-i386 -kernel $(NAME)

# TEST Réel : Boot l'ISO avec accélération KVM
# On ajoute -vga std pour être sûr que l'affichage VGA fonctionne bien
run_iso: $(ISO)
	qemu-system-i386 -enable-kvm -cdrom $(ISO) -vga std

clean:
	rm -rf $(OBJDIR) $(ISODIR)
	@echo "Objets et isodir nettoyés."

fclean: clean
	rm -f $(NAME) $(ISO)
	@echo "Binaire et ISO supprimés."

re: fclean all

.PHONY: all clean fclean re test run_iso
