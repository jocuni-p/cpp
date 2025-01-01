/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:54:34 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/31 14:03:51 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*----Default constructor----*/

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called" << std::endl;
}

/*--------Constructor overload--------*/

WrongCat::WrongCat(const std::string& type) : WrongAnimal(type) {
	std::cout << "WrongCat overloaded constructor called for " << _type << std::endl;
}

/*----Copy constructor----*/

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy) {
	std::cout << "WrongCat copy constructor called for " << _type << std::endl;
}

/*----Assignment operator overloaded----*/

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if(this != &other) {
		this->_type = other._type;
	}
	std::cout << "WrongCat assignment operator called for " << _type << std::endl;
	return *this;
}

/*--------Destructor---------*/

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called for " << _type << std::endl;
}

/*--------Member functions---------*/

void	WrongCat::makeSound(void) const {
	std::cout << std::endl << "WrongCat " << _type << " sounds like Wrong grrrrrrr" << std::endl;
}
