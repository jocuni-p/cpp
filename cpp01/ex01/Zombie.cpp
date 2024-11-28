/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:24:57 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/28 22:33:28 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


/*------Constructor-------*/

Zombie::Zombie(){}

/*-------Destructor-------*/

Zombie::~Zombie(){
	std::cout << "***Destructed Zombie " << _name << "***" << std::endl;	
}


void	Zombie::announce(void){
	std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
	//expresable tambien asi: this->_name
	//expresable tambien asi: Zombie::_name
}

void	Zombie::setName(std::string name){
	_name = name;
}
