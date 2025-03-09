/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:28:30 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/08 20:23:39 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstddef> // size_t


template <typename T, typename F> // iter accepts normal functions and instantiated function templates
void iter(T* arr, size_t len, F func) {
	if (!arr) // pointer check
		return;
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}

template <typename T>
void printElem(T& element) {
	std::cout << element << std::endl;
}

/* just for numeric types */
template <typename T>
void addOne(T& element) {
	element += 1;
}


#endif
