/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:15:43 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/02 18:29:03 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>


class Animal {
	protected:
		std::string		_type; // Accesible from this class and its derived classes
	
	public: // accesible from everywhere of the program
		Animal(); 	// Default constructor
		virtual ~Animal(); 	// Destroyer. Virtual para que se destruya tambien su clase derivada si se creo a traves de un puntero.
		Animal(const Animal& copy); // Copy constructor
//		Animal(const std::string& type); // Parameterized constructor
		Animal&			operator=(const Animal& other); // Copy asignment operator overloaded
		
		std::string		getType(void) const;		
		virtual void	makeSound() const; // permite ser sobreescrito por clases derivadas
		

};

#endif
