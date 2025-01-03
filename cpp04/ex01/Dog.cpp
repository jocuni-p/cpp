/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:19:11 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/03 18:16:41 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*----Default constructor----*/

Dog::Dog() {
	_type = "Dog";
	_dogbrain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

/*--------Destructor---------*/

Dog::~Dog() {
	std::cout << "Dog destructor called for " << _type << std::endl;
	delete _dogbrain;
}

/*----Copy constructor----*/

Dog::Dog(const Dog& other) : Animal(other) {
//	*this = other; // aqui usara la sobrecarga del operador de asignacion
	std::cout << "Dog copy constructor called for " << _type << std::endl;
}

/*----Assignment operator overloaded----*/

Dog& Dog::operator=(const Dog& other) {
	if(this != &other) {
		this->_type = other._type;
	}
	std::cout << "Dog assignment operator called for " << _type << std::endl;
	return *this;
}

/*--------Member functions---------*/

void	Dog::makeSound(void) const {
//	std::cout << std::endl << getType() << " makes Woof! Woof!" << std::endl;
	std::cout << _type << " makes Woof! Woof!" << std::endl;
	
}

