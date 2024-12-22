# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 15:49:52 by jocuni-p          #+#    #+#              #
#    Updated: 2024/12/21 19:17:20 by jocuni-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fixed_more

# Nombre del compilador
CXX = c++

# Flags de compilación (opcional)
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic #-fsanitize=address

# Flags para las dependencias
DEPFLAGS = -MMD -MP

# Archivos fuente
SRCS = main.cpp ClapTrap.cpp

# Archivos header (para incluirlos como dependencias y evitar re-link al compilar)
HDR = ClapTrap.hpp

# Directorio para los objetos
DIR_OBJS = objs/

# Archivos objeto (creados a partir de los archivos fuente)
OBJS = $(addprefix $(DIR_OBJS), $(SRCS:.cpp=.o))

DEPS = $(OBJS:.o=.d)

# Regla por defecto (se ejecuta al invocar `make` sin argumentos)
all: $(DIR_OBJS) $(NAME)

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)
	
# Regla para compilar el ejecutable
$(NAME): $(OBJS) Makefile
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Regla para compilar archivos .cpp en archivos .o
# Incluyo HDR como dependencia (si cambia algo en .hpp el compilador regenerara los archivos .o relacionados)
$(DIR_OBJS)%.o: %.cpp $(HDR)
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
