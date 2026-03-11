NAME        = woody_woodpacker

# Compilateur et Flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

# Sources et Objets
SRCS        = woody_woodpacker.c
OBJS        = $(SRCS:.c=.o)

# Couleurs pour le terminal (optionnel mais sympa)
GREEN       = \033[0;32m
RED         = \033[0;31m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)[SUCCESS]$(RESET) $(NAME) created."

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "$(RED)[CLEAN]$(RESET) Object files removed."

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[FCLEAN]$(RESET) Binary removed."

re: fclean all

.PHONY: all clean fclean re
