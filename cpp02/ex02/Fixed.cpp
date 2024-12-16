/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:16:00 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/16 16:31:18 by jocuni-p         ###   ########.fr       */
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
/** Este constructor usa un int como parametro para inicializar 
 * la variable _rawValue que es un fixed-point. Lo logra desplazando 
 * a la izquierda 8 bits del int para tener el espacio para los 
 * bits fraccionales. 
 */
Fixed::Fixed(const int num){
	std::cout << "Int constructor called" << std::endl;
	this->_rawValue = num << this->_fractBits;
}

/**-------Float constructor--------
 * convierte el parametro de punto flotante num a una representación
 *  interna de punto fijo y lo almacena en _rawValue
 */
Fixed::Fixed(const float num){  
	std::cout << "Float constructor called" << std::endl;
	_rawValue = static_cast<int>(roundf(num *(1 << _fractBits)));
//	desplaza el valor 1 a la izq por 8 bits, convirtiendo la parte
//decimal del flotante en punto-fijo. Redondea para tener mas precision que un simple truncado 
}

/*------Copy constructor------*/
/**
 * Se llama cuando se crea un nuevo objeto copiando otro existente.
 * Se le pasa como parametro una referencia del objeto a copiar existente y es const porque no lo va a cambiar
 * Copiamos el valor de su atributo privado en nuestro objeto 
 * */
Fixed::Fixed(const Fixed& other){
	
	std::cout << "Copy constructor called" << std::endl;
	*this = other; // usamos el operador de asignacion de copia que ya tenemos
}

/*------Copy assignment operator------*/
/* Se llama cuando se asigna un objeto ya existente a otro ya existente*/
Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) // verifica que no se este autoasignando
		this->_rawValue = other.getRawBits();
	return *this;
}

/*-----Destructor------*/

Fixed::~Fixed(){
	
	std::cout << "Destructor called" << std::endl;
}


/*===========Member functions============*/

int	Fixed::getRawBits(void) const {
//	std::cout << "getRawBits member function called" << std::endl;
	return _rawValue;
}


void	Fixed::setRawBits(int const raw){
	_rawValue = raw;
//	std::cout << "setRawBits member function called" << std::endl;
}


//Convierte _rawValue a un entero desplazando bits hacia la derecha
int	Fixed::toInt(void) const { //fixed-point to Integer
	return _rawValue >> _fractBits;
}


/* convierte el rawValue en un float dividiendolo por 2 elevado a fractionalBits */
float	Fixed::toFloat(void) const { // fixed-point to float
	return static_cast<float>(_rawValue) / (1 << _fractBits);
}

/*=============Overload operator implementation==============*/
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
