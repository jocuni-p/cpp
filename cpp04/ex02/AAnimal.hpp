/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:15:43 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/02/28 22:39:20 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>


class AAnimal {
	protected:
		std::string		_type; // Accesible from this class and its derived classes
	
	public: // accesible from everywhere of the program
		AAnimal(); //Default constructor
		AAnimal(const std::string& type); // Parameterized constructor
		// Destructor virtual: para que se llamen correctamente los destructores 
		// de las clases derivadas si se creo a traves de un puntero.
		virtual ~AAnimal(); 
		AAnimal(const AAnimal& copy); // Copy constructor
		AAnimal&			operator=(const AAnimal& other); // Copy asignment operator overloaded
		
		const std::string&		getType(void) const;		
		virtual void	makeSound() const = 0; // declaro una funcion virtual como pura (=0) y asi la clase deviene abstracta.
};

#endif
