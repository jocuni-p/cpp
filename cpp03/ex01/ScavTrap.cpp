/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:22:01 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/27 17:45:21 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
//#include "ClapTrap.hpp"


/*----Default constructor----*/

ScavTrap::ScavTrap() : ClapTrap("default") {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

/*--------Constructor overload--------*/

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap overloaded constructor called for " << _name << std::endl; //chequear si _name sale bien
}

/*----Copy constructor----*/

ScavTrap::ScavTrap(const ScavTrap& other) {
	std::cout << "ScavTrap copy constructor called for " << _name << std::endl; //chequear si _name sale bien
	*this = other;
//	_name = other._name; // Alternativa
//	_hitPoints = other._hitPoints; // Alternativa
//	_energyPoints = other._energyPoints; // Alternativa
//	_attackDamage = other._attackDamage; // Alternativa
}

/*----Copy asignment operator overloaded----*/

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if(this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "ScavTrap copy asignment operator called for " << _name << std::endl; //chequear si _name sale bien
	return *this;
}

/*--------Destructor---------*/

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

/*------Member functions-------*/

void	ScavTrap::attack(const std::string& target) {
	if (_energyPoints == 0 || _hitPoints == 0) {
		std::cout << "ScavTrap " << _name << " can not attack, it has not enough 'hit' or 'energy'!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}

