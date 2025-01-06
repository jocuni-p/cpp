/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:19:58 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/06 16:52:49 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*----Default constructor----*/

Cat::Cat() : Animal("Cat"), _brain(new Brain()) {
//	_type = "Cat"; 
//	_brain = new Brain();
	std::cout << "Cat created" << std::endl; // se printa despues de crear Brain
}

/*--------Destructor---------*/

Cat::~Cat() {
	delete _brain; // No estic segur si fa falta
	std::cout << "Cat destroyed" << std::endl;
}

/*----Copy constructor----*/

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain)){
	std::cout << "Cat " << _type << " copied" << std::endl; //TODO eliminar _type
}

/*----Assignment operator overloaded----*/

Cat& Cat::operator=(const Cat& other) {
	if(this != &other) {
		Animal::operator=(other);
		*_brain = *other._brain;
	}
//	std::cout << "Cat assignment operator called for " << _type << std::endl;
	return *this;
}

/*--------Member functions---------*/

void	Cat::makeSound(void) const {
	std::cout << _type << " makes Meeeeow!!" << std::endl;
}
