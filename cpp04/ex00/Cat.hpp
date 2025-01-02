/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:19:48 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/02 19:21:47 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal { //La clase derivada tiene una herencia tipo 'public' 

	public: // accesible from everywhere of the program
		Cat(); 	// Default constructor
		~Cat(); 	// Destroyer
//		Cat(const std::string& type); // Overload constructor
		Cat(const Cat& other); // Copy constructor
		Cat&	operator=(const Cat& other); // Assignment operator overloaded
				
		void	makeSound() const;
};
#endif
