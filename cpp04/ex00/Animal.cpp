/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:15:58 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/07 14:58:34 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*----Default constructor----*/

Animal::Animal() : _type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

/*--------Destructor---------*/

Animal::~Animal() {
	std::cout << "Animal destructor called for " << _type << std::endl;
}

/*----Copy constructor----*/

Animal::Animal(const Animal& other) : _type(other._type){
	std::cout << "Animal copy constructor called for " << _type << std::endl;
}

/*----Assignment operator overloaded----*/

Animal& Animal::operator=(const Animal& other) {
	if(this != &other) {
		this->_type = other._type;
	}
	std::cout << "Animal assignment operator called for " << _type << std::endl;
	return *this;
}

/*--------Member functions--------*/

void	Animal::makeSound() const {
	std::cout << "Animal doesn't make any sound" << std::endl;
}

/*-------Accessors---------*/

std::string	Animal::getType(void) const {
	return _type;
}
