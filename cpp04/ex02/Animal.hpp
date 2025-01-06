/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:15:43 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/06 22:27:23 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>


class Animal {
	protected:
		std::string		_type; // Accesible from this class and its derived classes
	
	public: // accesible from everywhere of the program
		Animal(); //Default constructor
		Animal(const std::string& type); // Parameterized constructor
		// Destructor virtual: para que se llamen correctamente los destructores 
		// de las clases derivadas si se creo a traves de un puntero.
		virtual ~Animal(); 
		Animal(const Animal& copy); // Copy constructor
		Animal&			operator=(const Animal& other); // Copy asignment operator overloaded
		
		const std::string&		getType(void) const;		
		virtual void	makeSound() const = 0; // declaro una funcion virtual como pura (=0) y asi toda la clase deviene abstracta.
};

#endif
