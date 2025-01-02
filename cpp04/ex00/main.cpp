/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:35:45 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/02 21:49:07 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "//// MANDATORY TEST ////" << std::endl << std::endl;
	const Animal* meta = new Animal(); // new crea dinámicamente un objeto de tipo Animal en el heap y devuelve un puntero a él.
	std::cout << "   ---" << std::endl;
	const Animal* j = new Dog(); // El objeto al que apunta el puntero no puede ser modificado a traves del puntero
	std::cout << "   ---" << std::endl;
	const Animal* i = new Cat();
	std::cout << "   ---" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "   ---" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	delete meta;
	delete j;
	delete i;
	
	std::cout << std::endl << "//// MY OWN TEST ////" << std::endl << std::endl;
	/*--extra tests--*/
	
	return 0;
}

