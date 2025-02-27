/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:40:49 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/31 21:49:47 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*----Default constructor----*/

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

/*--------Constructor overload--------*/

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Overloaded constructor called for ClapTrap " << _name << std::endl; //chequear si _name sale bien
}

/*----Copy constructor----*/

ClapTrap::ClapTrap(const ClapTrap& other) {
	*this = other; // aqui usara la sobrecarga del operador de asignacion
//	_name = other._name; // Alternativa
//	_hitPoints = other._hitPoints; // Alternativa
//	_energyPoints = other._energyPoints; // Alternativa
//	_attackDamage = other._attackDamage; // Alternativa
	std::cout << "Copy constructor called for ClapTrap " << _name << std::endl; //chequear si _name sale bien
}

/*--------Destructor---------*/

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called for ClapTrap " << _name << std::endl;
}

/*----Copy asignment operator overloaded----*/

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if(this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "Copy asignment operator called for ClapTrap " << _name << std::endl; //chequear si _name sale bien
	return *this;
}

/*-------Accessor member functions--------*/

std::string	ClapTrap::getName(void) const {
	return _name;
}

unsigned int	ClapTrap::getHit(void) const {
	return _hitPoints;
}

unsigned int	ClapTrap::getEnergy(void) const {
	return _energyPoints;
}

unsigned int	ClapTrap::getDamage(void) const {
	return _attackDamage;
}


/*--------Member functions----------*/

void	ClapTrap::attack(const std::string& target) {
	if (_energyPoints == 0 || _hitPoints == 0) {
		std::cout << "Claptrap " << _name << " can not attack, it has not enough 'hit' or 'energy'!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "Claptrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "Claptrap " << _name << " is already down and cannot takeDamage!" << std::endl;
		return;
	}
	_hitPoints = (amount >= _hitPoints) ? 0 : (_hitPoints - amount);
	std::cout << "Claptrap " << _name << " takeDamage of " << amount << " hitPoints!" << std::endl;
	if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is dead!!!!!!" << std::endl;
    }
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints == 0 || _hitPoints == 0) {
		std::cout << "Claptrap " << _name << " can't beRepaired because it has not enough 'hit' or 'energy'!" << std::endl;
		return;
	}
	_energyPoints--;		
	_hitPoints += amount;
	std::cout << "Claptrap " << _name << " repairs itself, recovering " << amount << " hitPoints!" << std::endl; 
}

void	ClapTrap::printStatus(void) const {

//	std::cout << "*** "<< getName() << " status ***" << std::endl;
	std::cout << std::endl << "//" << getName() << " hitPoints:    " << getHit() << std::endl;
	std::cout << "//" << getName() << " energyPoints: " << getEnergy() << std::endl;
	std::cout << "//" << getName() << " attackDamage: " << getDamage() << std::endl << std::endl;
}
