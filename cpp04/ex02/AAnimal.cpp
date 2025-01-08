/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:15:58 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/08 16:41:50 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/*----Default constructor----*/

AAnimal::AAnimal() { //: _type("Default") {
	std::cout << "Abstract AAnimal type " << _type << " created" << std::endl;
}

/*----Parameterized constructor----*/

AAnimal::AAnimal(const std::string& type) : _type(type) { // Provar si funciona be
	std::cout << "Abstract AAnimal type " << _type << " created" << std::endl;
}

/*--------Destructor---------*/

AAnimal::~AAnimal() {
	std::cout << "Abstract AAnimal type " << _type << " destroyed" << std::endl;
}

/*----Copy constructor----*/

AAnimal::AAnimal(const AAnimal& other) : _type(other._type){
	std::cout << "Abstract AAnimal type " << _type << " copied" << std::endl;
}

/*----Assignment operator overloaded----*/

AAnimal& AAnimal::operator=(const AAnimal& other) {
	if(this != &other) {
		this->_type = other._type;
	}
	return *this;
}

/* ELIMINAMOS LA IMPLEMENTACION DE ESTA FUNCION EN LA CLASE ABSTRACTA*/
// void	AAnimal::makeSound() const {
// 	std::cout << "AAnimal " << _type << " does not make sound" << std::endl; //TODO arreglar texte
//}

/*-------Accessors---------*/

const std::string&	AAnimal::getType(void) const {
	return _type;
}
