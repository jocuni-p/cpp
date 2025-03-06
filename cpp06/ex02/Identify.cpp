/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:32:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/06 12:34:48 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib> // rand() srand()
#include <ctime> // time()
#include "Identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


/* It randomly instanciates A, B or C and returns the instance as a Base pointer.*/
Base* generate(void){
	int i = rand() % 3; // genera el aleatorio
	
	if (i == 0)
		return new A();
	else if (i ==1)
		return new B();
	else
		return new C();
}


/* Identifies the type of object pointed to by p using dynamic_cast (pointer version). */
/* It prints the actual type of the object pointed to by p: "A", "B" or "C".*/
/*Si dynamic_cast<tipo*>(ptr) no puede castear devuelve nullptr*/
void identify(Base* p){
	if (!p){
		std::cout << "Base* is a NULL pointer." << std::endl;
		return;
	}
	if (dynamic_cast<A*>(p))
		std::cout << "Base* points to an 'A' object." << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Base* points to a 'B' object." << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Base* points to a 'C' object." << std::endl;
	else
		std::cout << "Base* points to an UNKNOWN TYPE" << std::endl;
}

/* Identifies the type of object using dynamic_cast with reference. */
/* It prints the actual type of the object pointed to by p: "A", "B" or "C".*/
/*Si dynamic_cast<tipo&>(ref) no puede castear lanza una exception*/
void identify(Base& p){
	try {
		dynamic_cast<A&>(p);
		std::cout << "Base& references an 'A' object." << std::endl;
		return;
	}
	catch(...){//catch generico, captura cualquier exception sin importar el tipo
		std::cout << "catch 1" << std::endl;
	}
	try {
		dynamic_cast<B&>(p);
		std::cout << "Base& references a 'B' object." << std::endl;
		return;
	} 
	catch(...){
		std::cout << "catch 2" << std::endl;
	}
	try {
		dynamic_cast<C&>(p);
		std::cout << "Base* references a 'C' object." << std::endl;
		return;	
	} 
	catch(...){
		std::cout << "catch 3" << std::endl;
	}
	
	std::cout << "Base& references an UNKNOWN TYPE" << std::endl;
}

