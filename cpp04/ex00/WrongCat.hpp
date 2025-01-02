/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:53:56 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/31 13:58:16 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal { //AVERIGUAR PERQUE AQUI public 
		
	public: // accesible from everywhere of the program
		WrongCat(); 	// Default constructor
		~WrongCat(); 	// Destroyer
//		WrongCat(const std::string& type); // Overload constructor
		WrongCat(const WrongCat& other); // Copy constructor
		WrongCat&	operator=(const WrongCat& other); // Assignment operator overloaded
				
		void	makeSound() const;
};

#endif

