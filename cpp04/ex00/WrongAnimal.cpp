/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:46:29 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/31 13:49:14 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*----Default constructor----*/

WrongAnimal::WrongAnimal() : _type("def_WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

/*--------Constructor overload--------*/

WrongAnimal::WrongAnimal(const std::string& type) : _type(type) {
	std::cout << "WrongAnimal overloaded constructor called for " << _type << std::endl;
}

/*----Copy constructor----*/

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	*this = other; // aqui usara la sobrecarga del operador de asignacion
	std::cout << "WrongAnimal copy constructor called for " << _type << std::endl;
}

/*----Assignment operator overloaded----*/

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if(this != &other) {
		this->_type = other._type;
	}
	std::cout << "WrongAnimal assignment operator called for " << _type << std::endl;
	return *this;
}

/*--------Destructor---------*/

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called for " << _type << std::endl;
}

/*-------Accessors---------*/

std::string	WrongAnimal::getType(void) const {
	return _type;
}