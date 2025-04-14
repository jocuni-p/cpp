NAME = PmergeMe

SRC = main.cpp PmergeMe.cpp

OBJ = $(SRC:.cpp=.o)

CXX = c++ 

CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Makefile PmergeMe.hpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
