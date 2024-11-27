/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 00:40:07 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/27 17:15:23 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*------Constructor-------*/

Zombie::Zombie(std::string name){ //Constructor, puc expresar tambe aixi: Zombie()
	this->_name = name;
//expresable tambien asi: _name = name
	std::cout << "***Constructed Zombie " << this->_name << "***" << std::endl;
//tambien puedo expresarlo asi Zombie::_name 
}

Zombie::~Zombie(){
	std::cout << "***Destructed Zombie " << this->_name << "***" << std::endl << std::endl;	
}


void	Zombie::announce(void)
{
	std::cout << Zombie::_name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
	//expresable tambien asi: this->_name
	//expresable tambien asi: _name
}
