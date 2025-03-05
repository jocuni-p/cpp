/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:32:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/05 13:21:37 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib> // rand() srand()
#include <ctime> // time()
#include "Identify.hpp"


/* It randomly instanciates A, B or C and returns the instance as a Base pointer.*/
Base* generate(void){
	srand(time(0)); // Inicializa la semilla del generador de aleatorios
	int i = rand() % 3; // genera el aleatorio
	if (i == 0)
		return new A();
	else if (i ==1)
		return new B();
	else
		return new C();
}


/* It prints the actual type of the object pointed to by p: "A", "B" or "C".*/
void identify(Base* p){
	if (p)
		if (dynamic_cast<A*>(p))
			std::cout << "Base* 'p' points to an 'A' object." << std::endl;
		else if (dynamic_cast<B*>(p))
			std::cout << "Base* 'p' points to an 'B' object." << std::endl;
		else if (dynamic_cast<C*>(p))
			std::cout << "Base* 'p' points to an 'C' object." << std::endl;
		else
			std::cout << "Base* 'p' points to an UNKNOWN TYPE" << std::endl;
}


/* It prints the actual type of the object pointed to by p: "A", "B" or "C".*/
void identify(Base& p){
	try {
		dynamic_cast<A&>(p);
		std::cout << "Base& 'p' references to an 'A' object." << std::endl;
		return;
	}
	catch(...){}
	try {
		dynamic_cast<B&>(p);
		std::cout << "Base& 'p' references to an 'B' object." << std::endl;
		return;
	} catch(...){}
	try {
		dynamic_cast<C&>(p);
		std::cout << "Base* 'p' references to an 'C' object." << std::endl;
		return;	
	} catch(...) {}
	
	std::cout << "Base& 'p' references to an UNKNOWN TYPE" << std::endl;
}
