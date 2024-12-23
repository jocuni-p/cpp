/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:40:49 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/23 15:05:07 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*----Default constructor----*/

ClapTrap::ClapTrap() : _name("default"), _hit(10), _energy(10), _damage(0) {
	std::cout << "Default constructor called" << std::endl;
}

/*--------Constructor overload--------*/

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hit(10), _energy(10), _damage(0) {
	std::cout << "Overloaded constructor called" << std::endl;
}

/*----Copy constructor----*/

ClapTrap::ClapTrap(const ClapTrap& other) {
	*this = other;
}

/*----Copy asignment operator overload----*/

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Copy asignment operator called" << std::endl;
	if(this != &other)
		this->_name = other._name;
		this->_hit = other._hit;
		this->_energy = other._energy;
		this->_damage = other._damage;
	return *this;
}

/*--------Destructor---------*/

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}
