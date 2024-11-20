# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 16:52:12 by jocuni-p          #+#    #+#              #
#    Updated: 2024/11/20 16:33:09 by jocuni-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del compilador
CXX = g++

# Flags de compilación (opcional)
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Nombre del ejecutable
NAME = phonebook

# Archivos fuente
SRCS = main.cpp PhoneBook.cpp Contact.cpp

# Archivos objeto (creados a partir de los archivos fuente)
OBJS = $(SRCS:.cpp=.o)

# Regla por defecto (se ejecuta al invocar `make` sin argumentos)
all: $(NAME)

# Regla para compilar el ejecutable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Regla para compilar archivos .cpp en archivos .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar archivos generados
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


# Esto indica que all, clean, fclean y re no son archivos, 
# sino "etiquetas" para comandos de make.
.PHONY: all clean fclean re
