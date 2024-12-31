/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:45:43 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/31 14:55:18 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include<iostream>

class WrongAnimal
{
	public: // accesible from everywhere of the program
		WrongAnimal(); 	// Default constructor
		~WrongAnimal(); 	// Destroyer
		WrongAnimal(const std::string& type); // Overload constructor
		WrongAnimal(const WrongAnimal& copy); // Copy constructor
		WrongAnimal&	operator=(const WrongAnimal& other); // Copy asignment operator overloaded

	protected:
		std::string	_type; // Accesible from this class and its derived classes
		
		std::string	getType(void) const;
};

#endif

