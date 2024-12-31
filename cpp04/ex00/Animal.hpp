/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:15:43 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/31 14:40:58 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include<iostream>


class Animal {
	
	public: // accesible from everywhere of the program
		Animal(); 	// Default constructor
		~Animal(); 	// Destroyer
		Animal(const std::string& type); // Overload constructor
		Animal(const Animal& copy); // Copy constructor
		Animal&	operator=(const Animal& other); // Copy asignment operator overloaded
		
	protected:
		std::string	_type; // Accesible from this class and its derived classes

		std::string	getType(void) const;		
	
};

#endif
