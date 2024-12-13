/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:16:00 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/13 12:12:11 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

/*-----Default Constructor-----*/

Fixed::Fixed() : _rawValue(0) { //Forma optima de inicializar

	std::cout << "Default constructor called" << std::endl;
}


/*-----Destructor------*/

Fixed::~Fixed(){
	
	std::cout << "Destructor called" << std::endl;
}


/*------Copy constructor------*/
/* Se llama cuando se crea un nuevo objeto copiando otro existente.*/
Fixed::Fixed(const Fixed& other){
	
	std::cout << "Copy constructor called" << std::endl;
//	this->_rawValue = other._rawValue; // Alternativa
//	_rawValue = other._rawValue; // Alternativa
//	Fixed::setRawBits(other.getRawBits()); //Alternativa
	this->_rawValue = other.getRawBits(); // Forced by the subject

}


/*------Copy assignment operator------*/
/* Se llama cuando se asigna un objeto ya existente a otro ya existente*/
Fixed& Fixed::operator=(const Fixed& other){
	
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) // verifica que no se este autoasignando
//		this->_rawValue = other._rawValue; // Alternativa
		this->_rawValue = other.getRawBits(); // Forced by the subject
	return *this;
}



int	Fixed::getRawBits(void) const {
	
	std::cout << "getRawBits member function called" << std::endl;
	return _rawValue;
}


void	Fixed::setRawBits(int const raw){
	_rawValue = raw;
	std::cout << "setRawBits member function called" << std::endl;
}
