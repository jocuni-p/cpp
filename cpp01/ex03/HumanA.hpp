/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:15:56 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/04 15:25:59 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA
{
private:
	std::string	_name;
	Weapon&		_weaponA; // Existira siempre porque es una ref

public:
	HumanA(std::string name, Weapon& w);//& porque la weapon ya esta creada
	~HumanA();
	
	void	attack();
};

#endif
