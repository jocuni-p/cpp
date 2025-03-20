/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:20:11 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/20 17:50:15 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"


int main()
{
	MutantStack<int> mstack;
	
	mstack.push(1);
	mstack.push(2);

	std::cout << "MutantStack<int> mstack;" << std::endl;
	std::cout << mstack.top() << std::endl;

	mstack.pop();
	
	std::cout << mstack.size() << std::endl;
	
	std::cout << "----" << std::endl;
	
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);
	mstack.push(6);
	
	
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it; // Incrementa el puntero del iterador
	--ite;
	
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	std::cout << "----" << std::endl;

	std::cout << *it << std::endl;
	std::cout << *ite << std::endl;

	std::cout << "----" << std::endl;

	std::cout << "std::stack<int> s(mstack);" << std::endl;
	
	std::stack<int> s(mstack);
	/* Crea una copia clase stack de mstack pero no tendra sus
	iteradores porque el constructor de copia la hace de la clase
		base stack. */

	//imprimimos los elementos de la pila para comprobar que ha hecho una copia independiente de mstack
	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop(); // elimino el elemento de arriba de la pila
	}

	std::cout << "----" << std::endl;

//	std::cout << s.top() << std::endl;  // Como esta vacio nos dara un segfault
	std::cout << *it << std::endl;

	*it = 7;
	
	std::cout << *it << std::endl;

	std::cout << "----" << std::endl;

	MutantStack<int> mutconst;
	mutconst.push(10);
	mutconst.push(11);
	mutconst.push(12);

	std::cout << "MutantStack<int> mutconst;" << std::endl;
	
	MutantStack<int>::const_iterator itc = mutconst.begin();
	std::cout << *itc << std::endl;
	++itc;
//	*itc = 100; // No me permite reasignarlo porque es const_iterator
	std::cout << *itc << std::endl;

	return 0;
}


