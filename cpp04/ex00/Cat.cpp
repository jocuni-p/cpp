/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:19:58 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/31 12:33:57 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*----Default constructor----*/

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
}

/*--------Constructor overload--------*/

Cat::Cat(const std::string& type) : Animal(type) {
	std::cout << "Cat overloaded constructor called for " << _type << std::endl;
}

/*----Copy constructor----*/

Cat::Cat(const Cat& copy) : Animal(copy) {
	std::cout << "Cat copy constructor called for " << _type << std::endl;
}

/*----Assignment operator overloaded----*/

Cat& Cat::operator=(const Cat& other) {
	if(this != &other) {
		this->_type = other._type;
	}
	std::cout << "Cat assignment operator called for " << _type << std::endl;
	return *this;
}

/*--------Destructor---------*/

Cat::~Cat() {
	std::cout << "Cat destructor called for " << _type << std::endl;
}

/*--------Member functions---------*/

void	Cat::makeSound(void) const {
	std::cout << std::endl << _type << " sounds like baaaark" << std::endl;
}