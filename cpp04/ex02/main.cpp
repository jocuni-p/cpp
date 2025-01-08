/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:19:47 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/08 16:37:12 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"


int main()
{
	
	std::cout << std::endl;
	std::cout << "=== SUBJECT TEST ===" << std::endl;
	const AAnimal* j = new Dog();
	std::cout << "----" << std::endl;
	const AAnimal* i = new Cat();
	std::cout << std::endl;

	delete j;//should not create a leak
	std::cout << "----" << std::endl;
	delete i;


	std::cout << std::endl;
	std::cout << "=== ARRAY OF AAnimal OBJECTS TEST ===" << std::endl;
	 
	AAnimal *animal_arr[4]; // Declaro un puntero de tipo AAnimal de 4 elementos

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
//	AAnimal abst;
	std::cout << "'AAnimal' class objects are NOT instantiable because it is an abstract class" << std::endl;
	
	
	std::cout << std::endl;
	std::cout << "=== COPY TEST ===" << std::endl;
	Cat a;
	std::cout << "----" << std::endl;
	Cat b = a;
	std::cout << "----" << std::endl;
	
	return 0;
}

