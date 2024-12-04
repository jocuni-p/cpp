/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:03:13 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/04 18:46:19 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


/*---Constructor---*/

HumanB::HumanB(std::string name)
{
	_name = name;
	std::cout << "*** Constructor HumanB '" << _name << "' called ***" << std::endl;
}

/*---Destructor---*/

HumanB::~HumanB()
{
	std::cout << "*** Destructor '" << _name << "' called ***" << std::endl;	
}
void	HumanB::attack()
{
	std::cout << _name << " attacks with their " << _weaponB->getType() <<std::endl;
}

void	HumanB::setWeapon(Weapon& x) //no entiendo porque aqui toma una ref
{
	_weaponB = &x; 
}
