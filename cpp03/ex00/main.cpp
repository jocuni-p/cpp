/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:09:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/01 14:31:28 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(){
	
	ClapTrap def;
	ClapTrap thor("thor");
	ClapTrap phil("phil");
	
	def = ClapTrap ("jack"); // Al no tener nombre NO la puedo usar despues de aqui y se destruye

	def.printStatus();
	
	thor.attack("phil");
	thor.printStatus();
	
	thor.takeDamage(3);
	thor.printStatus();
	
	thor.attack("phil");
	thor.beRepaired(1);
	thor.printStatus();
	for (int i = 0; i < 9; i++) {
		thor.attack("phil");
	}
	thor.printStatus();
	thor.takeDamage(9);
	thor.printStatus();

	phil.printStatus();
	def.takeDamage(10);
	
	return 0;
}

