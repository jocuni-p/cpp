
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:38:55 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/10 15:04:49 by jocuni-p         ###   ########.fr       */
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
	Array(); // Constructor default. Creates an empty array.
	Array(unsigned int n); // Const parameterized. Creates an array of n elements.
	Array(const Array& copy); // ATT. to deep copy
	Array& operator=(const Array& obj); // ATT. to deep copy
	~Array();

	
	class OutOfBoundsException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	
	
	T& operator[](unsigned int i); // operator overload to allow a secure access to the elements (avoiding overflow) 
	unsigned int size() const; // returns the number of elements in the array

};

#include "Array.tpp" // to be seen the implementation by the compiler

#endif
