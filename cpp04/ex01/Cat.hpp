/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:19:48 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/03 18:06:59 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal { 

	private:
		Brain	*_catbrain;

	public: // accesible from everywhere of the program
		Cat(); 	// Default constructor
		~Cat(); 	// Destroyer
		Cat(const Cat& other); // Copy constructor
		Cat&	operator=(const Cat& other); // Assignment operator overloaded
				
		void	makeSound() const;
};
#endif
