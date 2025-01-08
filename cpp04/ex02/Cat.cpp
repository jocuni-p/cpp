/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:19:58 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/08 16:40:04 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*----Default constructor----*/

Cat::Cat() : AAnimal("Cat"), _brain(new Brain()) {
	std::cout << _type << " created" << std::endl;
}

/*--------Destructor---------*/

Cat::~Cat() {
	delete _brain;
	std::cout << _type << " destroyed" << std::endl;
}

/*----Copy constructor----*/

Cat::Cat(const Cat& other) : AAnimal(other), _brain(new Brain(*other._brain)){
	std::cout << _type << " copied" << std::endl;
}

/*----Assignment operator overloaded----*/

Cat& Cat::operator=(const Cat& other) {
	if(this != &other) {
		AAnimal::operator=(other);
		*_brain = *other._brain; // Aqui aseguro la copia profunda
	}
	return *this;
}

/*--------Member functions---------*/

void	Cat::makeSound(void) const {
	std::cout << _type << " makes Meeeeow!!" << std::endl;
}
