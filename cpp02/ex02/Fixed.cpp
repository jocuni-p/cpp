/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:16:00 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/20 15:35:25 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"


/*=========Default Constructor===========*/
/*Entra automaticamente al instanciar un obj sin parametro*/
Fixed::Fixed() : _rawValue(0) { //Forma optima de inicializar
//	std::cout << "Default constructor called" << std::endl;
}

/*============Destructor============*/
/*Entra automaticamente cuando ya no se usa un objeto*/
Fixed::~Fixed(){
//	std::cout << "Destructor called" << std::endl;
}

/*=========Copy constructor=========*/
/**
 * Se usa cuando se crea un nuevo objeto copiando otro existente.
 * Se le pasa como parametro una referencia del objeto a copiar existente y es const porque no lo va a cambiar
 * Copiamos el valor de su atributo privado en nuestro objeto 
 * */
Fixed::Fixed(const Fixed& other){
//	std::cout << "Copy constructor called" << std::endl;
	*this = other; // usamos el operador de asignacion de copia que tenemos debajo
}

/*=======Copy assignment operator======*/
/* Se usa cuando se asigna un objeto ya existente a otro ya existente*/
Fixed& Fixed::operator=(const Fixed& other){
//	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) // protector, verifica que no se este autoasignando
		this->_rawValue = other.getRawBits();
	return *this;
}

/*==========Int constructor=========*/
/** Este constructor entra cuando se recibe un int como parametro.
 * Inicializa la variable _rawValue a un formato fixed-point, lo 
 * logra desplazando a la izquierda 8 bits del int para tener el
 *  espacio para los bits fraccionales. 
 */
Fixed::Fixed(const int num){
//	std::cout << "Int constructor called" << std::endl;
	this->_rawValue = num << this->_fractBits;
//	std::cout << "rawValue as fixed-point = " << _rawValue << std::endl;// TODO: remover
}

/**===========Float constructor==========*/
/** Convierte el parametro float 'num' a una representación interna 
 * de punto fijo y lo almacena en _rawValue. Lo hace desplazando el 
 * valor 1 a la izq por 8 bits, y luego redondea para tener mas 
 * precision que un simple truncado.
 */
Fixed::Fixed(const float num){  
//	std::cout << "Float constructor called" << std::endl;
	_rawValue = static_cast<int>(roundf(num *(1 << _fractBits)));
//	std::cout << "rawValue as fixed-point = " << _rawValue << std::endl;//TODO: remover
}

/*===========Access methods==============*/

int	Fixed::getRawBits(void) const {
//	std::cout << "getRawBits member function called" << std::endl;
	return _rawValue;
}

void	Fixed::setRawBits(int const raw){
	_rawValue = raw;
//	std::cout << "setRawBits member function called" << std::endl;
}


/*===========Member functions============*/
//Convierte _rawValue a un entero desplazandolo 8 bits hacia la derecha
// y asi descartando su parte fraccional
int	Fixed::toInt(void) const { //fixed-point to Integer
	return _rawValue >> _fractBits;
}

/* Convierte el rawValue en un float dividiendolo por 2 elevado a fractionalBits */
/* Nos da la representacion correcta del numero incluyendo la parte fraccional*/
float	Fixed::toFloat(void) const { // fixed-point to float
	return static_cast<float>(_rawValue) / (1 << _fractBits);
}


/*===========overload comparison operators============*/

bool	Fixed::operator>(const Fixed& fixed) const {
//	std::cout << "Overload '>'" << std::endl; // TODO: remover
	return this->_rawValue > fixed._rawValue;
}
bool	Fixed::operator<(const Fixed& fixed) const {
//	std::cout << "Overload '<'" << std::endl; // TODO: remover
	return this->_rawValue < fixed._rawValue;
}
bool	Fixed::operator>=(const Fixed& fixed) const {
//	std::cout << "Overload '>='" << std::endl; // TODO: remover
	return this->_rawValue >= fixed._rawValue;
}

bool	Fixed::operator<=(const Fixed& fixed) const {
//	std::cout << "Overload '<='" << std::endl; // TODO: remover
	return this->_rawValue <= fixed._rawValue;
}
	
bool	Fixed::operator==(const Fixed& fixed) const {
//	std::cout << "Overload '=='" << std::endl; // TODO: remover
	return this->_rawValue == fixed._rawValue;
}

bool	Fixed::operator!=(const Fixed& fixed) const {
//	std::cout << "Overload '!='" << std::endl; // TODO: remover
	return this->_rawValue != fixed._rawValue;
}


/*================overload arithmetic operators================*/

Fixed 	Fixed::operator+(const Fixed& fixed) const {
//	std::cout << "Overload '+'" << std::endl; // TODO: remover
	return Fixed(this->toFloat() + fixed.toFloat()); //returns a new Fixed class object constructed by the float constructor
}

Fixed 	Fixed::operator-(const Fixed& fixed) const {
//	std::cout << "Overload '-'" << std::endl; // TODO: remover
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed 	Fixed::operator*(const Fixed& fixed) const {
//	std::cout << "Overload '*'" << std::endl; // TODO: remover
	 return Fixed(this->toFloat() * fixed.toFloat());
//	this->setRawBits((this->toFloat() * fixed.toFloat())* (1 << this->_fractBits));//version de Roman
	return *this;
}

Fixed 	Fixed::operator/(const Fixed& fixed) const {
//	std::cout << "Overload '/'" << std::endl; // TODO: remover
	return Fixed(this->toFloat() / fixed.toFloat());
}

/*===========overload increment/decrement operators============*/

Fixed&	Fixed::operator++() { // Pre-increment. Increments and show the incremented value.
	++this->_rawValue; // incremento el valor del obj
	return *this; // devuelvo el obj con el valor incrementado
}

Fixed	Fixed::operator++(int) { // post-increment. Shows the current value and then increments it.
	Fixed tmp = *this; // creo una copia del obj
	this->_rawValue++; // incremento el valor en el obj
	return tmp; // devuelvo la copia previa al incremento
}

Fixed&	Fixed::operator--() { // pre-decrement
	--this->_rawValue;
	return *this;
}

Fixed	Fixed::operator--(int) {  // post-decrement
	Fixed tmp = *this;
	this->_rawValue--; // lo uso despues porque refleja mas visualmente lo que estamos haciendo, aunque asi --this->_rawValue seria igual.
	return tmp;
}

/*================overload member functions====================*/

Fixed&	Fixed::min(Fixed& fixed1, Fixed& fixed2){ // Permite que retorno y/o parametros puedan ser modificados
//	std::cout << "overload 'min'" << std::endl; // TODO: remove
	return (fixed1 < fixed2) ? fixed1 : fixed2; // '<' overloaded y uso del operador ternario
}

const Fixed&	Fixed::min(const Fixed& fixed1, const Fixed& fixed2) { // const no permite modificar ni argumentos ni return
//	std::cout << "overload const 'min'" << std::endl; // TODO: remove
	return (fixed1 < fixed2) ? fixed1 : fixed2;
}
Fixed&	Fixed::max(Fixed& fixed1, Fixed& fixed2) {
//	std::cout << "overload 'max'" << std::endl; // TODO: remove
	return (fixed1 > fixed2) ? fixed1 : fixed2;
}

const Fixed&	Fixed::max(const Fixed& fixed1, const Fixed& fixed2) {
//	std::cout << "overload const 'max'" << std::endl; // TODO: remove
	return (fixed1 > fixed2) ? fixed1 : fixed2;
}


/*=============Overload insertion operator==============*/

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
//	std::cout << "Overload '<<' " << std::endl;;
	out << fixed.toFloat();
	return out;
}
