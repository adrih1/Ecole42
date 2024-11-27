NAME = ex00

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		src/Bureaucrat.cpp \
		src/AForm.cpp \
		src/PresidentialPardonForm.cpp \
		src/RobotomyRequestForm.cpp \
		src/ShrubberyCreationForm.cpp \
		src/Intern.cpp



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
