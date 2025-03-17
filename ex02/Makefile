NAME	= dynamic
C++		= c++
CFLAG	= -Wall -Wextra -Werror -std=c++17 -fsanitize=address
SRC		= main.cpp Identify.cpp A.cpp B.cpp C.cpp Base.cpp
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