/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:03:13 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/30 17:49:30 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


/*---Constructor---*/

HumanB::HumanB()
{
	std::cout << "HumanB constructor called" << std::endl;
}

/*---Destructor---*/

HumanB::~HumanB()
{
	std::cout << "Destructor " << _name << "called" << std::endl;	
}
void	HumanB::attack()
{
	std::cout << _name << "attacks with their" << _weaponB <<std::endl;
}