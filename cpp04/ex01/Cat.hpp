/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:19:48 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/06 12:06:42 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
//#include <iostream>
//#include <string>

class Cat : public Animal { 

	private:
		Brain	*_brain; //Puntero de classe/tipo Brain

	public: // accesible from everywhere of the program
		Cat(); 	// Default constructor
		~Cat(); 	// Destroyer
		Cat(const Cat& other); // Copy constructor
		Cat&	operator=(const Cat& other); // Assignment operator overloaded
				
		void	makeSound() const;
};
#endif
