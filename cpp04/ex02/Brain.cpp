/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:07:59 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/06 13:56:11 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*----Default constructor----*/
/* No se hace explícita la inicialización de cada elemento porque el 
constructor no tiene ninguna información sobre cómo deben inicializarse 
los valores de ideas (el subject tampoco lo especifica)*/
Brain::Brain() {
	std::cout << "Brain created" << std::endl;
}

/*--------Destructor---------*/
/**El destructor no necesita iterar el array ideas porque el contenido 
 * no es dinámico (no usa memoria asignada con new).
 * Por otra parte, std::string tiene un destructor que limpia su propia 
 * memoria dinámica. Al destruir el objeto Brain, el compilador llama 
 * automáticamente a los destructores de cada std::string en el array.
 *  std::string es "gestionado automáticamente por el".
 * Por tanto, no es necesario hacer una limpieza manual de cada elemento.
*/
Brain::~Brain() {
	std::cout << "Brain destroyed" << std::endl;
}

/*----Copy constructor----*/
/** El constructor de copia no itera el array _ideas porque delega el trabajo 
 * de copiar a través del operador de asignación y asi evitar duplicar lógica.
 *  Esto asegura que se utilice la lógica de copia profunda ya implementada en
 *  el operador de asignación.
 *  Reutilizar el operador de asignación en lugar de duplicar la lógica evita
 *  errores y mantiene el código más claro y conciso.
 */
Brain::Brain(const Brain& other) {
	*this = other; // aqui usara la sobrecarga del operador de asignacion
	std::cout << "Brain copied" << std::endl;
}

/*----Assignment operator overloaded----*/
/** En este caso, es necesario iterar el array para copiar cada elemento de 
 * other.ideas a this->ideas, porque std::string requiere una copia individual
 *  para cada elemento. La copia profunda asegura que las modificaciones en el
 *  contenido del array ideas de un objeto no afecten a otros objetos Brain que
 *  hayan sido asignados a partir de él. */
Brain& Brain::operator=(const Brain& other) {
	if(this != &other)
		for(int i = 0; i < 100; i++) {
			_ideas[i] = other._ideas[i];
		}
	return *this;
}
