/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:19:00 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/31 15:00:29 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal { //AVERIGUAR PERQUE AQUI public 
		
	public: // accesible from everywhere of the program
		Dog(); 	// Default constructor
		~Dog(); 	// Destroyer
		Dog(const std::string& type); // Overload constructor
		Dog(const Dog& copy); // Copy constructor
		Dog&	operator=(const Dog& other); // Copy asignment operator overloaded
				
		void	makeSound() const;
};


#endif
