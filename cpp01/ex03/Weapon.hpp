/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:37:12 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/29 23:26:18 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
private:
	std::string	_type;
	
public: 
	Weapon::Weapon();
	Weapon::~Weapon();
	
	const std::string getType();//retorna una const reference a 'type' 
	void	setType(std::string type);//Inicialitza el atribut privat 'type' amb el que li passem per parametre
			
};


#endif
