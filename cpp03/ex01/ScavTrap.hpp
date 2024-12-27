/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:21:43 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/27 16:33:15 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

/** ScavTrap es una clase derivada/heredada/hija de ClapTrap que modifica el
 * valor de algunos atributos, de la funcion attack y anyade la funcion 
 * guardGate*/
class ScavTrap : public ClapTrap {
	
	public:
		ScavTrap(); 	// Default constructor
		~ScavTrap(); 	// Destructor
		ScavTrap(const std::string& name); // Overload constructor
		ScavTrap(const ScavTrap& copy); // Copy constructor
		ScavTrap& 		operator=(const ScavTrap& other); // Copy asignment operator overloaded
		
		/*------Member functions-------*/
		
		void			attack(const std::string& target);
		void			guardGate();
};
#endif

