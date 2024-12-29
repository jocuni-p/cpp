/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:09:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/29 22:20:40 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int	main(){

//	std::cout << std::endl << "=======TESTS FOR EX00=======" << std::endl << std::endl;
//	
//	ClapTrap def;
//	ClapTrap thor("thor");
//	ClapTrap phil("phil");
//	
//	def = ClapTrap ("jack"); // Al no tener nombre NO la puedo usar despues de aqui y se destruye
//
//	def.printStatus();
//	
//	thor.attack("phil");
//	thor.printStatus();
//	
//	thor.takeDamage(3);
//	thor.printStatus();
//	
//	thor.attack("phil");
//	thor.beRepaired(1);
//	thor.printStatus();
//	for (int i = 0; i < 9; i++) {
//		thor.attack("phil");
//	}
//	thor.printStatus();
//	thor.takeDamage(9);
//	thor.printStatus();
//
//	phil.printStatus();
//	def.takeDamage(10);
//
//	std::cout << std::endl << "=======TESTS FOR EX01=======" << std::endl << std::endl;
//	 
//	ClapTrap mike("mike"); // Overload constructor
//	mike.printStatus();
//	
//	ScavTrap jhon("jhon"); // Overload constructor
//	jhon.printStatus();
//	
//	ScavTrap pit("pit"); // Overloaded constructor
//	pit.printStatus();
//	pit.guardGate();
//	
//	mike = jhon; // copy asignment overload
//	mike.printStatus();
//	
//	pit.attack("jhon");
//	pit.printStatus();
//	jhon.takeDamage(20);
//	jhon.printStatus();
	
	std::cout << std::endl << "=======TESTS FOR EX02=======" << std::endl << std::endl;

    ClapTrap clap1("Clappy");	// Constructor overload
    clap1.printStatus();         // Muestra los valores de sus atributos

    ScavTrap scav1("Scavy");
    scav1.printStatus();

    FragTrap frag1("Fraggy");
    frag1.printStatus();

    frag1.highFivesGuys();       // Solicita un "high fives"

	frag1.attack("Clappy");
	frag1.printStatus();
	clap1.printStatus();

	std::cout << "// Destructors are called in reverse order due to FILO" << std::endl;
    return 0;
}
