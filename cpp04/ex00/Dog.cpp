/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:19:11 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/01 22:33:59 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*----Default constructor----*/

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
}

/*--------Parameterized Constructor--------*/

Dog::Dog(const std::string& type) : Animal(type) {
	std::cout << "Dog parameterized constructor called for " << _type << std::endl;
}

/*----Copy constructor----*/

Dog::Dog(const Dog& other) {
	*this = other; // aqui usara la sobrecarga del operador de asignacion
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

/*--------Destructor---------*/

Dog::~Dog() {
	std::cout << "Dog destructor called for " << _type << std::endl;
}

/*--------Member functions---------*/

void	Dog::makeSound(void) const {
	std::cout << std::endl << getType() << " sounds like baaaark" << std::endl;
	std::cout << std::endl << _type << " sounds like woof! woof!" << std::endl;
	
}
//com he d'accedir a type: amb '_type' o 'getType()' ????
