/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:18:34 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/22 18:01:32 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>


class ClapTrap
{
	private:
		std::string		name;
		int	hit;
		int	energy;
		int	damage;

	public:
	//	ClapTrap();
		ClapTrap(const std::string& name); // Constructor
		ClapTrap(); // Copy constructor
		~ClapTrap(); // Destructor
		


		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);






	
};


#endif