/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:30:05 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/28 18:15:50 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	std::string	input;
	
	std::cout << "Please, choose a zombie name to be saved in the STACK: ";
	if (!std::getline(std::cin, input)) // protection in case wrong read or EOF
	{
		std::cerr << std::endl << "Error: Failed to read input using 'std::getline'" << std::endl;
		std::cout << "Exited properly." << std::endl;
		return 1;
	}	
	randomChump(input);

	std::cout << "Now, choose a zombie name to be saved in the HEAP: ";
	if (!std::getline(std::cin, input)) // protection in case wrong read or EOF
	{
		std::cerr << std::endl << "Error: Failed to read input using 'std::getline'" << std::endl;
		std::cout << "Exited properly." << std::endl;
		return 1;
	}	
	Zombie *thePtrZ = newZombie(input);//puede vivir mas alla del ambito del main.
	thePtrZ->announce();
	delete(thePtrZ);
	//delete libera, pero antes invoca automaticamente al destructor del objeto thePtr en el heap
	return 0;
}

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

