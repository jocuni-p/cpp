/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:19:58 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/03 18:15:43 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*----Default constructor----*/

Cat::Cat() {
	_type = "Cat";
	_catbrain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

/*--------Destructor---------*/

Cat::~Cat() {
	std::cout << "Cat destructor called for " << _type << std::endl;
	delete _catbrain;
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
	std::cout << _type << " makes Meeeeow!!" << std::endl;
}
