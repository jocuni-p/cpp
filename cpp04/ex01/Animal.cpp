/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:15:58 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/07 12:59:56 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*----Default constructor----*/

Animal::Animal() : _type("Default") {
	std::cout << "Animal type " << _type << " created" << std::endl;
}

/*----Parameterized constructor----*/

Animal::Animal(const std::string& type) : _type(type) {
	std::cout << "Animal type " << _type << " created" << std::endl;
}

/*--------Destructor---------*/

Animal::~Animal() {
	std::cout << "Animal type " << _type << " destroyed" << std::endl;
}

/*----Copy constructor----*/
// La lista de inicialización permite que los miembros sean inicializados 
// directamente en el momento de la construcción. Es lo mas eficiente.
Animal::Animal(const Animal& other) : _type(other._type){
	std::cout << "Animal type " << _type << " copied" << std::endl;
}

/*----Assignment operator overloaded----*/

Animal& Animal::operator=(const Animal& other) {
	if(this != &other) {
		this->_type = other._type;
	}
	return *this;
}

/*--------Member functions--------*/

void	Animal::makeSound() const {
	std::cout << "Animal " << _type << " does not make sound" << std::endl;
}

/*-------Accessors---------*/

const std::string&	Animal::getType(void) const {
	return _type;
}
