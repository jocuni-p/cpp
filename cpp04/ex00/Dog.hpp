/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:19:00 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/02 18:44:43 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal { //AVERIGUAR PERQUE AQUI public 
		
	public: // accesible from everywhere of the program
		Dog(); 	// Default constructor
		~Dog(); 	// Destroyer
//		Dog(const std::string& type); // Parameterized constructor
		Dog(const Dog& copy); // Copy constructor
		Dog&	operator=(const Dog& other); // Copy asignment operator overloaded
				
		void	makeSound() const; 
};

#endif
