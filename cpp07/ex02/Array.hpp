/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:38:55 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/09 22:24:33 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
private:
	T* _data;
	unsigned int _size;

public:
	Array(); 							// Constructor default. Crea un array empty.
	Array(unsigned int n); 				// Const parameterized. Crea un array de n elements inicializado por default
	Array(const Array& copy); 			// OJO que sea copia profunda
	Array& operator=(const Array& obj); // OJO que sea deep copy
	~Array();							// destroyer

	size_t size() const; // returns the number of elements in the array
	T& operator[](unsigned int i);
}

#include "Array.tpp" // to be seen the implementation by the compiler

#endif
