/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:19:58 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/07 13:14:05 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*----Default constructor----*/

Cat::Cat() : Animal("Cat"), _brain(new Brain()) {
	std::cout << "Cat created" << std::endl; // se printa despues de construir Animal y Brain
}

/*--------Destructor---------*/

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat destroyed" << std::endl;
}

/*----Copy constructor----*/

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain)){
	std::cout << _type << " copied" << std::endl;
}

/*----Assignment operator overloaded----*/

Cat& Cat::operator=(const Cat& other) {
	if(this != &other) {
		Animal::operator=(other);
		*_brain = *other._brain;
	}
	return *this;
}

/*--------Member functions---------*/

void	Cat::makeSound(void) const {
	std::cout << _type << " makes Meeeeow!!" << std::endl;
}
