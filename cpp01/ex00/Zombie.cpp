/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 00:40:07 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/26 17:12:38 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*------Constructor-------*/

Zombie::Zombie(std::string name){ //Constructor, puc expresar tambe aixi: Zombie()
	this->_name = name;
	std::cout << "Zombie" << Zombie::_name << "constructor created." << std::endl;
}

Zombie::~Zombie(){
	std::cout << "Zombie destructor called" << std::endl;	
}


void	announce(void)
{
	std::cout << Zombie::_name << ":" << "BraiiiiiiinnnzzzZ..." << std::endl;
	
}