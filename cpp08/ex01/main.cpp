/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:06:30 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/17 22:47:36 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "Span.hpp"
/*
void printContainer(Span& sp) {
    std::cout << "[ ";
    for (std::vector<int>::iterator it = sp.begin(); it != sp.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "]" << std::endl;
}
*/
int main() {
	Span sp = Span(5); //Copy constructor creates an obj Span type initialised with 5 value

	sp.addNumber(1);
	sp.addNumber(6);
	sp.addNumber(53);
	sp.addNumber(-7);
	sp.addNumber(8);

	 // Imprimir directamente el vector interno de Span
	 std::cout << "Span [";
	 for (size_t i = 0; i < sp.getNumbers().size(); ++i) {
		 std::cout << sp.getNumbers()[i] << " ";
	 }
	 std::cout << "]" << std::endl;

	 
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::vector<int> bigList(10000);
	for (size_t i = 0; i < bigList.size(); ++i) {
    bigList[i] = i; 
	}
	


	return 0;
}
