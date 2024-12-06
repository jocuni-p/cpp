/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:35:08 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/06 20:40:18 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}


void	Harl::_debug(){
	std::cout << "This is a DEBUG message" << std::endl;
}

void	Harl::_info(){
	std::cout << "This is an INFO message" << std::endl;
}

void	Harl::_warning(){
	std::cout << "This is a WARNING message" << std::endl;
}

void	Harl::_error(){
	std::cout << "This is an ERROR message" << std::endl;
}










void	Harl::complain(std::string level){
	if (level == "DEBUG")
		_debug();
	else if (level == "INFO")
		info();
	else if (level == "WARNING")
		warning();
	else if (level == "ERROR")
		error();
	else
		????

}