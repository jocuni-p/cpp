/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:16:40 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/17 22:48:26 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <stdexcept> // logic_error, range_error, 
#include <algorithm> // max_element, min_element, sort,
#include <vector> 

 class Span {
	private:
		unsigned int _N;
		std::vector<int> _numbers;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &copy);
		Span &operator=(const Span &obj);
		~Span();

		void addNumber(const unsigned int num); // Anyade un num al span. Se usara para rellenar el span. Lanza exception si al llamarla ya tiene los N elementos almacenados
		const std::vector<int>& getNumbers() const; // to make a _numbers printer
		int shortestSpan(); // retorna el lapso menor que encuentra entre todos los nums. Lanza exception si no hay nada en el span o solo un numero
		int longestSpan(); // retorna lapso mayor. Lanza exception si no hay nada en el span o solo un numero
		//		void addNumRange() rellena el contenedor (usando range of iterators)
};

template <typename T>
void printContainer(T& container) {
	typename T::iterator it;
	for (it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

#endif

