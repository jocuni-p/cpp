/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:19:47 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/06 20:10:24 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp" // No estic segur si aquesta s'ha d'incloure


int main()
{
	std::cout << "=== SUBJECT TEST ===" << std::endl;
	const Animal* j = new Dog();
	std::cout << "----" << std::endl;
	const Animal* i = new Cat();
	std::cout << std::endl;
	delete j;//should not create a leak
	std::cout << "----" << std::endl;
	delete i;

	std::cout << std::endl;
	std::cout << "=== ARRAY OF ANIMAL OBJECTS TEST ===" << std::endl;
	 
	Animal *animal_arr[4]; // Declaro puntero tipo Animal de 4 elementos

	for(int i = 0; i < 4; i++){ // inicializo los elementos con obj Dog y Cat dinamicos
		if(i % 2 == 0 ){
			animal_arr[i] = new Dog();
			std::cout << "-" << std::endl;
		}
		else {
			animal_arr[i] = new Cat();
			std::cout << "-" << std::endl;
		}
	}

	for(int i = 0; i < 4; i++) { // cada elemento llama a su funcion makesound()
		animal_arr[i]->makeSound();
	}

//	*animal_arr[0] = *animal_arr[1]; // asignamos los Cat a los Dog
//	*animal_arr[2] = *animal_arr[3]; // asignamos los Cat a los Dog
	
//	std::cout << "===" << std::endl;

//	for(int i = 0; i < 4; i++) { // cada elemento llama a su funcion makesound()
//		animal_arr[i]->makeSound();
//	}
	
	std::cout << "===" << std::endl;
	for(int i = 0; i < 4; i++){ // se libera cada elemento
		delete animal_arr[i];
		std::cout << "-" << std::endl;
	}
	return 0;
}
