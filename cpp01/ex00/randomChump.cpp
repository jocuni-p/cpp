/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:00:00 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/28 18:34:11 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*Creates an object of Zombie class, name it with the input and announce it*/
void	randomChump(std::string name)
{
	if (name.empty())//return true is the string is empty, otherwise returns 0
		name = "unknown";
	Zombie	Chump(name);//Al constructor le paso el parametro name
	Chump.announce();
}
//al salir del ambito de la funcion automaticamente es invocado el destructor de los obejtos en el stack
