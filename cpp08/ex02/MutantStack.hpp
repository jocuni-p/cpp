/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:20:28 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/20 17:51:35 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack() : std::stack<T>(){}

		MutantStack(const MutantStack &copy) : std::stack<T>(copy) {}

		MutantStack &operator=(const MutantStack &obj){
			if (this != &obj)
				std::stack<T>::operator=(obj);
			return *this;
		}
		
		~MutantStack(){}

		/*Creo un alias llamado 'iterator' que representa al tipo iterator que 
		contiene el container subyacente a stack (que es un 'deque').
		Es decir, estamos usando el iterador de std::deque para darle un alias 
		en MutantStack. No estamos creando un nuevo tipo de iterador, solo estamos
		 accediendo a los iteradores existentes del contenedor subyacente y dándoles
		 un alias.
		*/
	
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator; 
		//El tipo const_iterator ya existe previamente en el contenedor subyacente 'deque'.
		

		//Con 'c' podemos acceder al contenedor subyacente de stack, porque 'c' es su nombre.
		iterator begin() { return this->c.begin(); } // El primer elemento insertado, el mas antiguo
		iterator end() { return this->c.end(); } // El ultimo insertado, el de arriba de la pila
		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }
};

#endif
