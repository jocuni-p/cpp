/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:19:11 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/08 16:44:57 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*----Default constructor----*/

Dog::Dog() : AAnimal("Dog"), _brain(new Brain()) {
	std::cout << _type << " created" << std::endl;
}

/*--------Destructor---------*/

Dog::~Dog() {
	delete _brain;
	std::cout << _type << " destroyed" << std::endl;
}

/*----Copy constructor----*/

Dog::Dog(const Dog& other) : AAnimal(other), _brain(new Brain(*other._brain)) { // copia profunda de brain
	std::cout << _type << " copied" << std::endl;
}

/*----Assignment operator overloaded----*/

Dog& Dog::operator=(const Dog& other) {
	if(this != &other) {
		AAnimal::operator=(other);
		*_brain = *other._brain; // Aqui aseguro la copia profunda
	}
	return *this;
}

/*--------Member functions---------*/

void	Dog::makeSound(void) const {
	std::cout << _type << " makes Woof! Woof!" << std::endl;
	
}

