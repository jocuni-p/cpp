/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:15:58 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/02 21:39:31 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*----Default constructor----*/

Animal::Animal() : _type("def_animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

/*--------Destructor---------*/

Animal::~Animal() {
	std::cout << "Animal destructor called for " << _type << std::endl;
}

/*----Copy constructor----*/

Animal::Animal(const Animal& other) : _type(other._type){
//	*this = other; // aqui usara la sobrecarga del operador de asignacion
	std::cout << "Animal copy constructor called for " << _type << std::endl;
}

/*----Assignment operator overloaded----*/

Animal& Animal::operator=(const Animal& other) {
	if(this != &other) {
		this->_type = other._type;
	}
	std::cout << "Animal assignment operator called for " << _type << std::endl;
	return *this;
}

/*--------Member functions--------*/

void	Animal::makeSound() const {
	std::cout << std::endl << "Animal doesn't make any sound" << std::endl << std::endl;
}

/*-------Accessors---------*/

std::string	Animal::getType(void) const {
	return _type;
}
