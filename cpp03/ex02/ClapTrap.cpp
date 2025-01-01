/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:40:49 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/01 14:51:20 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*----Default constructor----*/

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

/*--------Parameterized constructor--------*/

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap parameterized constructor called for " << _name << std::endl; //chequear si _name sale bien
}

/*----Copy constructor----*/

ClapTrap::ClapTrap(const ClapTrap& other) {
	*this = other; // aqui usara la sobrecarga del operador de asignacion
	std::cout << "ClapTrap copy constructor called for " << _name << std::endl; //chequear si _name sale bien
}

/*----Copy assignment operator overloaded----*/

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if(this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap assignment operator called for " << _name << std::endl; //chequear si _name sale bien
	return *this;
}

/*--------Destructor---------*/

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called for " << _name << std::endl;
}


/*-------Accessor member functions--------*/

std::string	ClapTrap::getName(void) const {
	return _name;
}

unsigned int	ClapTrap::getHitPoints(void) const {
	return _hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints(void) const {
	return _energyPoints;
}

unsigned int	ClapTrap::getAttackDamage(void) const {
	return _attackDamage;
}

void	ClapTrap::setName(const std::string& name) {
	_name = name;
}

void	ClapTrap::setHitPoints(int hitPoints) {
	_hitPoints = (hitPoints < 0) ? 0 : hitPoints;
//	if (hitPoints < 0) _hitPoints = 0;
//	else _hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints(int energyPoints) {
	_energyPoints = (energyPoints < 0) ? 0 : energyPoints;
//	if (energyPoints < 0) _energyPoints = 0;
//	else _energyPoints = energyPoints;
}

void	ClapTrap::setAttackDamage(int attackDamage) {
	_attackDamage = (attackDamage < 0) ? 0 : attackDamage;
//	if (attackDamage < 0) _attackDamage = 0;
//	else _attackDamage = attackDamage;
}


/*--------Member functions----------*/

void	ClapTrap::attack(const std::string& target) {
	if (getEnergyPoints() == 0 || getHitPoints() == 0) {
		std::cout << "Claptrap " << _name << " can not attack, it has not enough 'hit' or 'energy'!" << std::endl;
		return;
	}
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout << "Claptrap " << _name << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (getHitPoints() == 0) {
		std::cout << "Claptrap " << _name << " is already down and cannot takeDamage!" << std::endl;
		return;
	}
	setHitPoints((amount >= getHitPoints()) ? 0 : (getHitPoints() - amount));
	std::cout << "Claptrap " << _name << " takeDamage of " << amount << " hitPoints!" << std::endl;
	if (getHitPoints() == 0) {
        std::cout << "ClapTrap " << _name << " is dead!!!!!!" << std::endl;
    }
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (getEnergyPoints() == 0 || getHitPoints() == 0) {
		std::cout << "Claptrap " << _name << " can't beRepaired because it has not enough 'hit' or 'energy'!" << std::endl;
		return;
	}
	setEnergyPoints(getEnergyPoints() - 1);
//	_hitPoints += amount;
	setHitPoints(getHitPoints() + amount);		
	std::cout << "Claptrap " << _name << " repairs itself, recovering " << amount << " hitPoints!" << std::endl; 
}

void	ClapTrap::printStatus(void) const {
	std::cout << std::endl << "//" << " name:         " << getName() << std::endl;
	std::cout << "//" << " hitPoints:    " << getHitPoints() << std::endl;
	std::cout << "//" << " energyPoints: " << getEnergyPoints() << std::endl;
	std::cout << "//" << " attackDamage: " << getAttackDamage() << std::endl << std::endl;
}
