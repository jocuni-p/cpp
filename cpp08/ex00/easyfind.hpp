/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:16:06 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/21 17:30:22 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <list>
#include <vector>
#include <deque>

/*
La funcion busca un int dentro de un container y retornara un iterador de tipo T.
La funcion debera ser compatible con cualquier container que soporte iteradores
y con el algoritmo std::find(), que contiene los métodos .begin() y
 .end(), que permite recorrer sus elementos de manera secuencial.
 */

template <typename T>  // T sera un container de int
typename T::iterator easyfind(T& container, int nbr) {
	typename T::iterator it = std::find(container.begin(), container.end(), nbr);
	if (it == container.end())
		throw std::invalid_argument("Number not found!");
	return it;
}

template <typename T>
void printContainer(T& container) {
	typename T::iterator it;
	for (it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

#endif

