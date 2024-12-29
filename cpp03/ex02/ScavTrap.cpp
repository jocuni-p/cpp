/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:22:01 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/29 20:43:00 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
//#include "ClapTrap.hpp"


/*----Default constructor----*/

ScavTrap::ScavTrap() : ClapTrap("default") {
	setHitPoints(100); // Usamos los metodos de acceso protected, porque los atributos son private
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTrap default constructor called for " << getName() << std::endl;
}

/*--------Constructor overload--------*/

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	setHitPoints(100); // Usamos los metodos de acceso protected, porque los atributos son private
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTrap overloaded constructor called for " << getName() << std::endl; //chequear si _name sale bien
}

/*----Copy constructor----*/

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy){
	std::cout << "ScavTrap copy constructor called for " << getName() << std::endl; //chequear si _name sale bien
//	_name = other._name; // Alternativa
//	_hitPoints = other._hitPoints; // Alternativa
//	_energyPoints = other._energyPoints; // Alternativa
//	_attackDamage = other._attackDamage; // Alternativa
}

/*----Assignment operator overloaded----*/

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if(this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap assignment operator called for " << getName() << std::endl; //chequear si _name sale bien
	return *this;
}

/*--------Destructor---------*/

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called for " << getName() << std::endl;
}

/*------Member functions-------*/

void	ScavTrap::attack(const std::string& target) {
	if (getEnergyPoints() == 0 || getHitPoints() == 0) {
		std::cout << "ScavTrap " << getName() << " can not attack, it has not enough 'hit' or 'energy'!" << std::endl;
		return;
	}
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode" << std::endl;
}

