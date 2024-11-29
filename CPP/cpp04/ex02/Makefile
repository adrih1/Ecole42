NAME = ex02

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		src/Animal.cpp \
		src/Dog.cpp \
		src/Cat.cpp \
		src/Brain.cpp \
		src/WrongAnimal.cpp \
		src/WrongCat.cpp 

OBJS = $(SRCS:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
