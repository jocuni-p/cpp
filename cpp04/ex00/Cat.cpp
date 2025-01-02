/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:19:58 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/02 21:41:18 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*----Default constructor----*/

Cat::Cat() {
	_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

/*--------Destructor---------*/

Cat::~Cat() {
	std::cout << "Cat destructor called for " << _type << std::endl;
}

/*----Copy constructor----*/

Cat::Cat(const Cat& other) : Animal(other) {
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

/*--------Member functions---------*/

void	Cat::makeSound(void) const {
	std::cout << std::endl << _type << " makes Meeeeow!!" << std::endl;
}
