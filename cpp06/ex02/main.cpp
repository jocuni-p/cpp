/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:52:35 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/05 17:39:49 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Identify.hpp"
#include "Base.hpp"


int main() {

	srand(time(0)); // Inicializa la semilla del generador de aleatorios
	
	Base* p = generate(); //genera/instancia un obj de una clase derivada de Base y lo asigno al puntero Base* p

	identify(p); // identifica a que clase derivada de Base pertenece el obj apuntado por p
				// castea el puntero a Base en un puntero a su clase derivada correcta 

	identify(*p);//ahora desreferencio el puntero y lo passo como referencia para que identifique a que clase pertenece la ref
	
	Base* t = generate();
	identify(t);
	identify(*t);
	
	Base* w = generate();
	identify(w);
	identify(*w);
	
	Base* h = generate();
	identify(h);
	identify(*h);
	
	delete p;
	delete t;
	delete w;
	delete h;
	
	return 0;
}