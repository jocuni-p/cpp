/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:04:09 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/30 11:48:46 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

/*---Constructor---*/

Weapon::Weapon()
{
	std::cout << "*** Constructor Weapon called ***" << std::endl;
}


/*---Destructor---*/

Weapon::~Weapon()
{
	std::cout << "*** Destructor " << _type << "called ***" << std::endl;
}

/*---Access methods---*/

const std::string Weapon::getType()
{
	const std::string& typeREF = _type;
	return typeREF;
}

void	Weapon::setType(std::string type)
{
	_type = type;
}
