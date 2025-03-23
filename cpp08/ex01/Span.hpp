/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:16:40 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/21 17:32:31 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <stdexcept> // logic_error, range_error, 
#include <vector>	// insert, size



 class Span {
	private:
		unsigned int _N;
		std::vector<int> _numbers;

	public:
		/* Canonical form */
		Span();
		Span(unsigned int N);
		Span(const Span &copy);
		Span &operator=(const Span &obj);
		~Span();

		/* Main methods */
		void addNumber(const unsigned int num); 
		int shortestSpan(); 
		int longestSpan(); 
		void addNumRange(std::vector<int>::iterator begin, std::vector<int>::iterator end); // fills the container in one shot, using a range of iterators

		/* Aux method */
		const std::vector<int>& getNumbers() const; // to access the container to print it
};


#endif

