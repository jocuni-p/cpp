/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:30:05 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/28 11:33:41 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{

	
	randomChump("Betsy");
	randomChump("Jack");
	
	Zombie *thePtrZ = newZombie("Stormy");//puede vivir mas alla del ambito del main.
	thePtrZ->announce();
	delete(thePtrZ);
	//delete libera e invoca automaticamente al destructor del objeto thePtr en el heap
	return 0;
}
//Al salir del ambito de la funcion donde se define




/*
int	main()
{
	randomChump("Betsy");
	randomChump("Jack");
	
	Zombie *thePtrZ = newZombie("Stormy");//puede vivir mas alla del ambito del main.
	thePtrZ->announce();
	delete(thePtrZ);
	//delete libera e invoca automaticamente al destructor del objeto thePtr en el heap
	return 0;
}*/
//Al salir del ambito de la funcion donde se define
