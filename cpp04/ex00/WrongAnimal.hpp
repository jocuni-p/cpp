/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:45:43 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/02 19:30:27 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string		_type; // Accesible from this class and its derived classes
		
	public: // accesible from everywhere of the program
		WrongAnimal(); 	// Default constructor
		virtual ~WrongAnimal(); 	// Destroyer
//		WrongAnimal(const std::string& type); // Parameterized constructor
		WrongAnimal(const WrongAnimal& other); // Copy constructor
		WrongAnimal&	operator=(const WrongAnimal& other); // Copy assignment operator overloaded

		virtual void	makeSound() const; // permite ser sobreescrito por clases derivadas
		std::string		getType(void) const;		
};

#endif

