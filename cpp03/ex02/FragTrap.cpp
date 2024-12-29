/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:27:39 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/29 21:02:47 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


/*----Default constructor----*/

FragTrap::FragTrap() : ClapTrap("default") {
	setHitPoints(100); // Usamos los metodos de acceso protected, porque los atributos son private
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "FragTrap default constructor called for " << getName() << std::endl;
}

/*--------Constructor overload--------*/

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "FragTrap overloaded constructor called for " << getName() << std::endl; //chequear si _name sale bien
}

/*----Copy constructor----*/

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {
	std::cout << "FragTrap copy constructor called for " << getName() << std::endl; //chequear si _name sale bien
//	*this = other;
}

/*----Assignment operator overloaded----*/

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if(this != &other) {
		ClapTrap::operator=(other); // llama al operador de asignacion de ClapTrap
	}
	std::cout << "FragTrap assignment operator called for " << getName() << std::endl; //chequear si _name sale bien
	return *this;
}

/*--------Destructor---------*/

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called for " << getName() << std::endl;
}


/*------Member functions-------*/

void	FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << getName() << " says: High fives, guys! 🖐️" << std::endl << std::endl;
}
