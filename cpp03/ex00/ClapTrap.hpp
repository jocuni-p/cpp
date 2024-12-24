/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:18:34 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/24 17:15:16 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>


class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage; 

	public:
		ClapTrap(); 	// Default constructor
		~ClapTrap(); 	// Destructor
		ClapTrap(const std::string& name); // Overload constructor
		ClapTrap(const ClapTrap& copy); // Copy constructor
		ClapTrap& 		operator=(const ClapTrap& other); // Copy asignment operator overloaded
		
		/*--------Accessors----------*/
		std::string 	getName(void) const;
		unsigned int	getHit(void) const;
		unsigned int	getEnergy(void) const;
		unsigned int	getDamage(void) const;
		
		/*------Member functions-------*/
		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			printStatus(void) const;
};


#endif
