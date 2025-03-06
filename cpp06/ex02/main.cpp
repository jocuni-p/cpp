/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:52:35 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/06 12:33:51 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Identify.hpp"
#include "Base.hpp"


int main() {

	srand(time(0)); // Inicializa la semilla del generador de aleatorios
	
	/*TEST PUNTERO NULL*/
	Base* n = NULL; 
	identify(n);
	identify(*n);
	std::cout << "*****" << std::endl;


	/*TEST GENERAL*/
	Base* p = generate(); //genera/instancia un obj de una clase (aleatoria) derivada de Base
	identify(p); // identifica a que clase derivada de Base pertenece el obj apuntado por p
				// castea el puntero a Base en un puntero a su clase derivada correcta 
	identify(*p);//desreferencio el ptr y lo paso como ref para que identifique a que clase derivada pertenece
	std::cout << "*****" << std::endl;
	
	Base* t = generate();
	identify(*t);
	identify(t);
	std::cout << "*****" << std::endl;
	
	Base* w = generate();
	identify(w);
	identify(*w);
	std::cout << "*****" << std::endl;
	
	Base* h = generate();
	identify(h);
	identify(*h);
	std::cout << "*****" << std::endl;
	
	delete p;
	delete t;
	delete w;
	delete h;
	
	return 0;
}