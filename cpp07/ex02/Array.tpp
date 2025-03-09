/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:50:29 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/09 22:22:09 by jocuni-p         ###   ########.fr       */
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
		_data[i] = copy.data[i];
	}
}

/*Overload assignement operator for copy*/
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& obj) {
	if (this != &copy){
		
		
	}
	return 

}

template <typename T>
Array<T>::~Array() { delete[] _data; }

