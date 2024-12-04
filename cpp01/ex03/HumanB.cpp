/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:03:13 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/04 19:55:20 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


/*---Constructor---*/

HumanB::HumanB(std::string name) : _name(name), _weaponB(NULL)
{
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

void	HumanB::setWeapon(Weapon& x) //pasamos la ref para garantizar que se pase un objeto valido y que no se haga una copia
{
	_weaponB = &x; //guardamos la direccion de memoria del objeto referenciado por x
}
