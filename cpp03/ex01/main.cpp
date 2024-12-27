/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:09:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/27 18:09:11 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int	main(){
	
	ClapTrap mike("mike"); // Overload constructor
	mike.printStatus();
	
	ScavTrap jhon("jhon"); // Overload constructor
	jhon.printStatus();
	
	ScavTrap pit("pit"); // Overloaded constructor
	pit.printStatus();

	ScavTrap def(jhon); // Copy constructor
	def.printStatus();
	
//	mike = jhon; // copy asignment overload
//	mike.printStatus();
	
//	pit.attack("jhon"); // esta y la siguiente son lo mismo
	pit.attack(jhon.getName());
	pit.printStatus();
	jhon.takeDamage(20);
	jhon.printStatus();
	pit.guardGate();
	
	return 0;
}
