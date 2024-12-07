/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:35:08 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/07 20:34:28 by jocuni-p         ###   ########.fr       */
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


/**
 * Implementa un puntero a función miembro para mapear las cadenas 
 * (debug, info, warning, error) a los métodos correspondientes.
 */
void	Harl::complain(std::string level){

	std::string option[4] = {"debug", "info", "warning", "error"};
	
//	Declaro un arreglo de punteros a funciones miembro de Harl que devuelven void y no tienen parámetros.
	void (Harl::*ptr[4])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
// 	El & nos da la direccion de memoria, o sea el puntero

	for (int i = 0; i < 4; i++)
	{
		if (level == option[i])
		{
			(this->*ptr[i])(); // Llama a la función miembro apuntada por ptr[i] en el contexto del objeto actual (this).
			return ;
		}
	}
	std::cout << "Invalid complain level" << std::endl;
}
