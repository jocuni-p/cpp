/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:45:43 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/01 21:35:15 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include<iostream>

class WrongAnimal
{
	public: // accesible from everywhere of the program
		WrongAnimal(); 	// Default constructor
		virtual ~WrongAnimal(); 	// Destroyer
		WrongAnimal(const std::string& type); // Parameterized constructor
		WrongAnimal(const WrongAnimal& copy); // Copy constructor
		WrongAnimal&	operator=(const WrongAnimal& other); // Copy asignment operator overloaded

		std::string		getType(void) const;
		virtual void	makeSound() const; // permite ser sobreescrito por clases derivadas
		
	protected:
		std::string		_type; // Accesible from this class and its derived classes
};

#endif

