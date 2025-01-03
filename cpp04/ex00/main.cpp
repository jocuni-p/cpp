/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:35:45 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/03 15:33:41 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << "//// SUBJECT TEST ////" << std::endl << std::endl;
		
		const Animal* meta = new Animal(); // new crea dinámicamente un objeto de tipo Animal en el heap y devuelve un puntero a él.
		const Animal* j = new Dog(); // El objeto al que apunta el puntero no puede ser modificado a traves del puntero
		const Animal* i = new Cat();
		std::cout << "---" << std::endl;
		
		std::cout << j->getType() << std::endl;
		std::cout << i->getType() << std::endl;
		std::cout << "---" << std::endl;
		
		meta->makeSound(); //will output the animal sound!
		j->makeSound(); //will output the dog sound!
		i->makeSound(); //will output the cat sound!
		std::cout << "---" << std::endl;
		
		delete meta;
		delete j; // Llama ~Dog() y luego ~Animal() si el destructor es virtual
		delete i; // Llama ~Cat() y luego ~Animal() si el destructor es virtual
	}
	{
		std::cout << std::endl << "//// WRONGCAT SOUND TEST ////" << std::endl << std::endl;

		const WrongAnimal* beta = new WrongAnimal(); // new crea dinámicamente un objeto de tipo Animal en el heap y devuelve un puntero a él.
		const Animal* j = new Dog(); // El objeto al que apunta el puntero no puede ser modificado a traves del puntero
		const WrongAnimal* i = new WrongCat();
		std::cout << "---" << std::endl;
		
		std::cout << beta->getType() << std::endl;
		std::cout << j->getType() << std::endl;
		std::cout << i->getType() << std::endl;
		std::cout << "---" << std::endl;

		beta->makeSound(); //will output the WrongAnimal sound!
		j->makeSound(); //will output the dog sound!
		i->makeSound(); //Won't output the WrongCat sound!
		std::cout << "---" << std::endl;
		
		delete beta;
		delete j; // Llama ~Dog() y luego ~Animal() si el destructor es virtual
		delete i; // Llama ~Cat() y luego ~Animal() si el destructor es virtual
	}
	return 0;
}

