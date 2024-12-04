/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:50:21 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/04 19:19:52 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/*---Constructor---*/

/* 
* Inicializo _weaponA usando la lista de inicialización del constructor.
* Las referencias no pueden ser reasignadas después de ser inicializadas, 
* por lo que es obligatorio hacerlo de esta manera.
*/
HumanA::HumanA(std::string name, Weapon& w) : _name(name), _weaponA(w)
{
std::cout << "*** Constructor HumanA '" << _name << "' called ***" << std::endl;
}


/*---Destructor---*/

HumanA::~HumanA()
{
	std::cout << "*** Destructor '" << _name << "' called ***" << std::endl;	
}
void	HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weaponA.getType() <<std::endl;
}
