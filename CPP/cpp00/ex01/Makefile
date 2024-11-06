# Nom de l'exécutable
NAME = ex01

# Compilateur et options
CC = c++
CFLAGS = -Wall -Wextra -Werror

# Fichiers source et fichiers objets
SRCS = 	main.cpp \
		Phonebook.cpp \
		Contact.cpp \



OBJS = $(SRCS:.cpp=.o)

# Commande de suppression
RM = rm -f

# Règle par défaut pour compiler l'exécutable
all: $(NAME)

# Règle de création de l'exécutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Règle pour compiler les fichiers objets
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers objets
clean:
	$(RM) $(OBJS)

# Règle pour nettoyer les fichiers objets et l'exécutable
fclean: clean
	$(RM) $(NAME)

# Règle pour refaire la compilation complète
re: fclean all

# Indique que certaines règles ne sont pas des fichiers
.PHONY: all clean fclean re
