/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:19:11 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/07 15:03:24 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*----Default constructor----*/

Dog::Dog() {
	_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

/*--------Destructor---------*/

Dog::~Dog() {
	std::cout << "Dog destructor called for " << _type << std::endl;
}

/*----Copy constructor----*/

Dog::Dog(const Dog& other) : Animal(other) {
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
	std::cout << _type << " makes Woof! Woof!" << std::endl;
}

