/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:15:58 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/06 22:31:07 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*----Default constructor----*/

Animal::Animal() : _type("Default") {
	std::cout << "Abstract Animal type " << _type << " created" << std::endl;
}

/*----Parameterized constructor----*/

Animal::Animal(const std::string& type) : _type(type) { // Provar si funciona be
	std::cout << "Abstract Animal type " << _type << " created" << std::endl;
}

/*--------Destructor---------*/

Animal::~Animal() {
	std::cout << "Abstract Animal type " << _type << " destroyed" << std::endl;
}

/*----Copy constructor----*/

Animal::Animal(const Animal& other) : _type(other._type){
//	*this = other; // aqui usara la sobrecarga del operador de asignacion
	std::cout << "Abstract Animal type " << _type << "copied" << std::endl;
}

/*----Assignment operator overloaded----*/

Animal& Animal::operator=(const Animal& other) {
	if(this != &other) {
		this->_type = other._type;
	}
//	std::cout << "Animal assignment operator called for " << _type << std::endl;
	return *this;
}

/*--------Member functions--------*/
/* ELIMINAMOS LA IMPLEMENTACION DE ESTA FUNCION EN LA CLASE ABSTRACTA*/
// void	Animal::makeSound() const {
// 	std::cout << "Animal " << _type << " does not make sound" << std::endl; //TODO arreglar texte
//}

/*-------Accessors---------*/

const std::string&	Animal::getType(void) const {
	return _type;
}
