/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:16:00 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/11 17:15:19 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	
	this->_rawValue = other._rawValue; // copiamos el atributo
	std::cout << "Copy constructor called" << std::endl;
}


/*------Copy assignment operator------*/
/* Se llama cuando se asigna un objeto ya existente a otro ya existente*/
Fixed& Fixed::operator=(const Fixed& other){
	
	if (this != &other) // verifica que no se este autoasignando
		this->_rawValue = other._rawValue;
	std::cout << "Copy assignment operator called" << std::endl;
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
