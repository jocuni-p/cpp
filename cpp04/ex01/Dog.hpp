/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:19:00 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/06 12:06:34 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
//#include <iostream> // ?
//#include <string> // ?

class Dog : public Animal {

	private:
		Brain	*_brain;
		
	public: // accesible from everywhere of the program
		Dog(); 	// Default constructor
		~Dog(); 	// Destroyer
		Dog(const Dog& copy); // Copy constructor
		Dog&	operator=(const Dog& other); // Copy asignment operator overloaded
				
		void	makeSound() const; 
};

#endif
