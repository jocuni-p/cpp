/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:27:54 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/28 22:25:29 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

/** FlagTrap es una clase derivada/heredada/hija de ClapTrap que modifica el
 * valor de algunos atributos, de la funcion attack y anyade la funcion 
 * guardGate*/
class FragTrap : public ClapTrap {

	public:
		FragTrap(); 	// Default constructor
		~FragTrap(); 	// Destroyer
		FragTrap(const std::string& name); // Overload constructor
		FragTrap(const FragTrap& copy); // Copy constructor
		
		FragTrap& 		operator=(const FragTrap& other); // Copy asignment operator overloaded
		
		void			highFivesGuys(void); // Member function
};
#endif

