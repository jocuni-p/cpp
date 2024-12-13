/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:16:00 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/13 20:01:21 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"


/*-----Default Constructor-----*/

Fixed::Fixed() : _rawValue(0) { //Forma optima de inicializar

	std::cout << "Default constructor called" << std::endl;
}

/*------Int constructor-------*/

Fixed::Fixed(const int num){
	std::cout << "Int constructor called" << std::endl;
	this->_rawValue = num << this->_fractBits;
}

/*-------Float constructor--------*/

Fixed::Fixed(const float num){  
	std::cout << "Float constructor called" << std::endl;
//	_rawValue = static_cast<int>(roundf(num *(1 << _fractBits)));
}

/*------Copy constructor------*/
/**
 * Se llama cuando se crea un nuevo objeto copiando otro existente.
 * Se le pasa como parametro una referencia del objeto a copiar existente y es const porque no lo va a cambiar
 * Copiamos el valor de su atributo privado en nuestro objeto 
 * */
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

/*-----Destructor------*/

Fixed::~Fixed(){
	
	std::cout << "Destructor called" << std::endl;
}


/*===========Member functions============*/

int	Fixed::getRawBits(void) const {
	
	std::cout << "getRawBits member function called" << std::endl;
	return _rawValue;
}


void	Fixed::setRawBits(int const raw){
	_rawValue = raw;
	std::cout << "setRawBits member function called" << std::endl;
}


/*------Member functions------*/
//Convierte rawValue a un entero desplazando bits hacia la derecha
int	Fixed::toInt(void) const { //fixed-point to Integer
	return _rawValue >> _fractBits; // El this no hace falta porque hay el Fixed al inicio de la function
}


float	Fixed::toFloat(void) const { // fixed-point to float
// convierte el rawValue en un float dividiendolo por 2 elevado a fractionalBits
	return static_cast<float>(getRawBits() / (1 << _fractBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}