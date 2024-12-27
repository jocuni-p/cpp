/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:21:43 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/27 14:18:03 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

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

