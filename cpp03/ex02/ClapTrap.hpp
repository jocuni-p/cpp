/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:18:34 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/28 22:58:02 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

/*=======OPTION A=======*/
/*
class ClapTrap 
{
	protected: // sera accesible tambien desde clases derivadas
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
		
		//--------Accessors----------
		
		std::string 	getName(void) const;
		unsigned int	getHit(void) const;
		unsigned int	getEnergy(void) const;
		unsigned int	getDamage(void) const;
		
		//------Member functions-------
		
		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			printStatus(void) const;
};
*/


/*=========OPTION B========*/
///*
class ClapTrap 
{
	private: // Las clases derivadas no pueden acceder aqui directamente
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage; 

	protected: // Accesible tambien desde clases derivadas
		//--------Accessors----------
		std::string 	getName(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;
		void			setName(const std::string&); // const para evitar modificaciones accidentales de la ref
		void			setHitPoints(int);
		void			setEnergyPoints(int);
		void			setAttackDamage(int);
		
		
	public: // accesible desde cualquier parte del programa
		ClapTrap(); 	// Default constructor
		~ClapTrap(); 	// Destroyer
		ClapTrap(const std::string& name); // Overload constructor
		ClapTrap(const ClapTrap& copy); // Copy constructor
		ClapTrap& 		operator=(const ClapTrap& other); // Copy asignment operator overloaded
		
		//------Member functions-------
		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			printStatus(void) const;
};
//*/
#endif
