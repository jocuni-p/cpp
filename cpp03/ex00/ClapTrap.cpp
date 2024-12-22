/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:40:49 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/22 17:57:03 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*--------Constructor--------*/

ClapTrap::ClapTrap(const std::string& name) : hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Constructor called" << std::endl;
}

/*--------Destructor---------*/

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}
