/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:00:00 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/27 16:35:04 by jocuni-p         ###   ########.fr       */
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
//al salir de la funcion se deberia activar el destructor
}
