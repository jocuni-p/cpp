/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:19:47 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/03 18:51:34 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp" // No estic segur si aquesta s'ha d'incloure


int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;


	Animal *animal_arr[6];
	
	for(int i = 0; i < 6; i++){
		if(i % 2 == 0 )
			animal_arr[i] = new Dog();
		else
			animal_arr[i] = new Cat();
	}
	
	/*--test code---*/
	
	for(int i = 0; i < 6; i++){
		delete animal_arr[i];
	}
	
	return 0;
}