/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:19:48 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/07 13:34:26 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Cat : public Animal { // Cat is an Animal derived class

	private:
		Brain	*_brain; //Puntero de classe/tipo Brain

	public:
		Cat();
		~Cat();
		Cat(const Cat& other); // Copy constructor
		Cat&	operator=(const Cat& other); // Assignment operator overloaded
				
		void	makeSound() const;
};
#endif
