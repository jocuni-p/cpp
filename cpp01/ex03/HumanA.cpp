/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:50:21 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/30 17:42:35 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


/*---Constructor---*/

HumanA::HumanA(Weapon type)
{
	_weaponA = type;
	std::cout << "HumanA constructor called" << std::endl;
}

/*---Destructor---*/

HumanA::~HumanA()
{
	std::cout << "Destructor " << _name << "called" << std::endl;	
}
void	HumanA::attack()
{
	std::cout << _name << "attacks with their" << _weaponA <<std::endl;
}