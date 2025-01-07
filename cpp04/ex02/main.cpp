/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:19:47 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/07 14:19:55 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"


int main()
{
	
	std::cout << std::endl;
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
	 
	Animal *animal_arr[4]; // Declaro puntero tipo Animal de 5 elementos

	for(int i = 0; i < 4; i++){ // inicializo 4 elementos con obj Dog y Cat dinamicos
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
	
	std::cout << "---" << std::endl;
	for(int i = 0; i < 4; i++){ // se libera cada elemento
		delete animal_arr[i];
		std::cout << "-" << std::endl;
	}

	
	std::cout << std::endl;
	std::cout << "=== ABSTRACT CLASS TEST ===" << std::endl;
//	Animal abst;
	std::cout << "error: variable type 'Animal' is an abstract class" << std::endl;
	
	
	std::cout << std::endl;
	std::cout << "=== COPY TEST ===" << std::endl;
	Cat a;
	std::cout << "----" << std::endl;
	Cat b = a;
	std::cout << "----" << std::endl;
	
	return 0;
}

