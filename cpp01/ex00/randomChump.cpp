/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:00:00 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/28 10:45:34 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump(std::string name)
{
//				crea una clase Zombie
//				le pone nombre
//				el zombie se anuncia
	Zombie	Chump(name);
	Chump.announce();
}
//al salir del ambito de la funcion automaticamente es invocado el destructor de los obejtos en el stack
