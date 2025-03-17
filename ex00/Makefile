NAME	= convert
C++		= c++
CFLAG	= -Wall -Wextra -Werror -std=c++17 -fsanitize=address
SRC		= main.cpp ScalarConverter.cpp check_input.cpp convert_input.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(C++) $(CFLAG) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re