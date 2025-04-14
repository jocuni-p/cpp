# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/02 17:15:20 by jocuni-p          #+#    #+#              #
#    Updated: 2025/04/14 21:04:04 by jocuni-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==========VARIABLES DEFINITION=============#

# Nombre del ejecutable
NAME = PmergeMe

# Nombre del compilador
CXX = c++

# Flags de compilación (opcional)
#OJO: comentar 'fsanitize' para debbugar.
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g -DPMERGEME_DEBUG #-fsanitize=address

# Flags para las dependencias
DEPFLAGS = -MMD -MP

# Archivos fuente
SRCS = main.cpp PmergeMe.cpp

# Directorio para los objetos
DIR_OBJS = objs/

# Archivos objeto (creados a partir de los archivos fuente)
OBJS = $(addprefix $(DIR_OBJS), $(SRCS:.cpp=.o))

DEPS = $(OBJS:.o=.d)

#============RULES================#

# Regla por defecto (se ejecuta al invocar `make` sin argumentos)
all: $(DIR_OBJS) $(NAME)
	@echo "SUCCESSFULLY COMPILED -> PmergeMe"

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)    
	
# Regla para compilar el ejecutable
$(NAME): $(OBJS) Makefile
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Regla para compilar archivos .cpp en archivos .o
# Incluyo HDR como dependencia (si cambia algo en .hpp el compilador regenerara los archivos .o relacionados)
$(DIR_OBJS)%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

# Regla para limpiar archivos generados
clean:
	rm -rf $(DIR_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

# .PHONY indica que all, clean, fclean y re no son archivos, 
# sino "etiquetas" para comandos de make.
.PHONY: all clean fclean re

