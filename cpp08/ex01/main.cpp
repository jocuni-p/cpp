/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:06:30 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/20 18:01:10 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "Span.hpp"


/* Prints the Span vector content */
void printNumbers(const Span& sp) {
    const std::vector<int>& numbers = sp.getNumbers();
    std::cout << "Span [ ";
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "]" << std::endl;
}


int main() {

	try {
		std::cout << "\n==== BASIC TEST ====" << std::endl;
	
		Span sp = Span(5); // Copy constructor creates a Span type obj initialised with 5 value

		sp.addNumber(1);

//		std::cout << sp.shortestSpan() << std::endl; // Uncomment the line to test
		
		sp.addNumber(6);
		sp.addNumber(53);
		sp.addNumber(-7);
		sp.addNumber(8);

		printNumbers(sp);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

//		sp.addNumber(0); // Uncomment to test overflows


		std::cout << "\n==== RANGE OF ITERATORS TEST ====" << std::endl;

		Span sp1 = Span(11);

		std::vector<int> moreNumbers(10); // Crea un vector de 10 elementos inicializados a 0
		for (int i = 0; i < 10; i++)
			moreNumbers[i] = i * 5;

		sp1.addNumRange(moreNumbers.begin(), moreNumbers.end());

		printNumbers(sp1);

		std::cout << sp1.shortestSpan() << std::endl;
		std::cout << sp1.longestSpan() << std::endl;
		

		std::cout << "\n==== BIG LIST TEST ====" << std::endl;

		Span sp2 = Span(10100);
		
		std::vector<int> bigList(10100);
		for (size_t i = 0; i < bigList.size(); ++i)
			bigList[i] = i * 2; // fills only the even numbers

		sp2.addNumRange(bigList.begin(), bigList.end());

//		printNumbers(sp2); // Uncomment to test
		
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

