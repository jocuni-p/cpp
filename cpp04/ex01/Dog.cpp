/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:19:11 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/06 16:10:42 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*----Default constructor----*/

Dog::Dog() : Animal("Dog"), _brain(new Brain()) {
//	_type = "Dog";
//	_brain = new Brain();
	std::cout << "Dog created" << std::endl; // se printa despues de creado Brain
}

/*--------Destructor---------*/

Dog::~Dog() {
	delete _brain; // quizas no hace falta si lo hace automatico ?? Provar
	std::cout << "Dog destroyed" << std::endl;
}

/*----Copy constructor----*/

Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*other._brain)) {
//	*this = other; // aqui usara la sobrecarga del operador de asignacion
	std::cout << "Dog copied" << std::endl;
}

/*----Assignment operator overloaded----*/

Dog& Dog::operator=(const Dog& other) {
	if(this != &other) {
		Animal::operator=(other);
		*_brain = *other._brain;
	}
//	std::cout << "Dog assignment operator called for " << _type << std::endl;
	return *this;
}

/*--------Member functions---------*/

void	Dog::makeSound(void) const {
//	std::cout << std::endl << getType() << " makes Woof! Woof!" << std::endl;
	std::cout << _type << " makes Woof! Woof!" << std::endl;
	
}

