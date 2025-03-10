/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:50:29 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/10 16:38:57 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/*Default constructor*/
template <typename T>
Array<T>::Array() : _size(0), _data(NULL) {}


/*Parameterized constructor*/
template <typename T>
Array<T>::Array(unsigned int n) : _size(n) { _data = new T[n]; }


/*Copy constructor*/
template <typename T>
Array<T>::Array(const Array& copy) : _size(copy._size) {
	_data = new T[_size];
	for (unsigned int i = 0; i < _size; i++){
		_data[i] = copy._data[i]; // deep copy
	}
}


/*Overload assignement operator for copy*/
template <typename T>
Array<T>& Array<T>::operator=(const Array& obj) {
	if (this != &obj){
		delete[] _data;
		_size = obj._size;
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; i++) {
			_data[i] = obj._data[i];
		}
	}
	return *this;
}


/*Destroyer*/
template <typename T>
Array<T>::~Array() { delete[] _data; }


/*Exception class inside Array class*/
template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
	return "Error: Index out of bounds!";
}

/*Overload subscript operator to prevent an out of bounds in the size of array*/
template <typename T>
T& Array<T>::operator[](unsigned int n) {
	if (n >= _size) {
		throw OutOfBoundsException();
	}
	return _data[n];
}

/*Accessor*/
template <typename T>
unsigned int Array<T>::size() const { return _size; }


