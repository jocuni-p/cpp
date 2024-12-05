/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:26:47 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/05 11:33:10 by jocuni-p         ###   ########.fr       */
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
	Weapon 		*_weaponB;//Lo hago puntero porque puede existir o no (NULL)

public:
	HumanB(std::string name);
	~HumanB();
	
	void	attack();
	void 	setWeapon(Weapon& x);//Si queremos que tenga weapon lo setearemos aqui
};

#endif
