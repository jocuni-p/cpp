/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:18:34 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/23 15:44:57 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>


class ClapTrap
{
	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage; 

	public:
		ClapTrap(); // Default constructor
		ClapTrap(const std::string& name); // Constructor for string
		ClapTrap(const ClapTrap& other); // Copy constructor
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap(); // Destructor
		

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);






	
};


#endif