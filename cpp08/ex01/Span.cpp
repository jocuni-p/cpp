/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:18:24 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/18 14:40:41 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits> // INT_MAX
#include <algorithm> // max_element, min_element, sort, min
#include <iterator> // distance

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span& copy) : _N(copy._N), _numbers(copy._numbers) {}

Span& Span::operator=(const Span& obj) {
	if (this != &obj) {
		_N = obj._N;
		_numbers = obj._numbers; // copies the container content
	}
	return *this;
}

Span::~Span() {} //Destruye el container automaticamente

void Span::addNumber(const unsigned int num) {
	if (_numbers.size() >= _N)
		throw std::range_error("Exception: Span is full");
	_numbers.push_back(num);
}


/*Find the smallest distance between numbers stored in the container */
int Span::shortestSpan() {
	if (_numbers.size() < 2)
		throw std::logic_error("Exception: Not enough numbers to calculate span");
		
	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end()); 
	
	int minSpan = INT_MAX;
	for (size_t i = 0; i < sortedNumbers.size() - 1; i++)
		minSpan = std::min(minSpan, sortedNumbers[i + 1] - sortedNumbers[i]);
	return minSpan;
}

/*Find the biggest distance between the numbers stored in the container */
int Span::longestSpan() {
	if (_numbers.size() < 2) // Counts how many numbers are already stored in vector
		throw std::logic_error("Exception: Not enough numbers to calculate span");
		
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	
	return max - min;
}

/* Adds multiple numbers using a range iterator */
void Span::addNumRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if ((_numbers.size() + distance(begin, end)) > _N)
		throw std::range_error("Exception: Not enough available space on the span to fit all numbers");
	_numbers.insert(_numbers.end(), begin, end);
}

/* Getter method for the container */
const std::vector<int>& Span::getNumbers() const {
	return _numbers;
}

