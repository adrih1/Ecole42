NAME        = woody_woodpacker

# Compilateur et Flags
CC          = cc
# Ajout de -I $(INCDIR) pour dire au compilateur où chercher woody.h
CFLAGS      = -Wall -Wextra -Werror -g -I $(INCDIR)

# Dossiers
SRCDIR      = src/
INCDIR      = inc/
OBJDIR      = obj/

# Fichiers sources (ajoute les nouveaux fichiers ici au fur et à mesure)
SRC_FILES   = main.c \
              utils.c \
              elf_parser.c \
              elf_patcher.c \
              injector.c \
              create_file.c \
			  payload.c

# Magie de Makefile : On ajoute le préfixe src/ et obj/ automatiquement
SRCS        = $(addprefix $(SRCDIR), $(SRC_FILES))
OBJS        = $(addprefix $(OBJDIR), $(SRC_FILES:.c=.o))

# Couleurs pour le terminal
GREEN       = \033[0;32m
RED         = \033[0;31m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)[SUCCESS]$(RESET) $(NAME) created."

# Règle pour compiler les .o dans le dossier obj/
$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@echo "$(RED)[CLEAN]$(RESET) Object directory removed."

fclean: clean
	@rm -f $(NAME)
	@rm -rf woody
	@echo "$(RED)[FCLEAN]$(RESET) Binary removed."

re: fclean all

.PHONY: all clean fclean re
