/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:26:47 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/04 19:52:24 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB
{
private:
	std::string	_name;
	Weapon 		*_weaponB;//puede existir o no, por que es *

public:
	HumanB(std::string name);
	~HumanB();
	
	void	attack();
	void 	setWeapon(Weapon& x);
};

#endif
