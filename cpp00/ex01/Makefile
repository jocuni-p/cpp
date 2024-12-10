# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 16:52:12 by jocuni-p          #+#    #+#              #
#    Updated: 2024/12/10 16:12:09 by jocuni-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del compilador
CXX = c++

# Flags de compilación (opcional)
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address

# Nombre del ejecutable
NAME = phonebook

# Archivos fuente
SRCS = main.cpp PhoneBook.cpp Contact.cpp

# Archivos header (para incluirlos como dependencias y evitar re-link al compilar)
HDR = Contact.hpp PhoneBook.hpp

# Archivos objeto (creados a partir de los archivos fuente)
OBJS = $(SRCS:.cpp=.o)

# Regla por defecto (se ejecuta al invocar `make` sin argumentos)
all: $(NAME)

# Regla para compilar el ejecutable
$(NAME): $(OBJS) Makefile
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Regla para compilar archivos .cpp en archivos .o
%.o: %.cpp $(HDR)
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
