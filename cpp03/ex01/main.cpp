/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:09:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/27 12:22:31 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int	main(){
	ClapTrap def;
	ClapTrap thor("thor");
	ClapTrap phil("phil");
	ClapTrap ("shan");

	thor.attack("phil");
	thor.printStatus();

	return 0;
}
