/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:18:24 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/17 22:46:29 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span& copy) : _N(copy._N), _numbers(copy._numbers) {}

Span& Span::operator=(const Span& obj) {
	if (this != &obj) {
		_N = obj._N;
		_numbers = obj._numbers;
	}
	return *this;
}

Span::~Span() {} //Destruye el container automaticamente

void Span::addNumber(const unsigned int num) {
	if (_numbers.size() >= _N)
		throw std::range_error("Exception: Span is full");
	_numbers.push_back(num);
}

const std::vector<int>& Span::getNumbers() const {
	return _numbers;
}

/*Find the smallest distance between numbers stored in the container */
int Span::shortestSpan() {
	if (_numbers.size() < 2)
		throw std::logic_error("Exception: Not enough numbers to calculate span");
		
	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	
	int minSpan = sortedNumbers[1] - sortedNumbers[0];
	for (size_t i = 0; i < sortedNumbers.size() - 1; i++) {
		int tempMinSpan = sortedNumbers[i + 1] - sortedNumbers[i];
		if (tempMinSpan < minSpan)
			minSpan = tempMinSpan;
	}
	return minSpan;
}

/*Find the biggest distance between the numbers stored in the container */
int Span::longestSpan() {
	if (_numbers.size() < 2)
		throw std::logic_error("Exception: Not enough numbers to calculate span");
		
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	
	return max - min;
}

//void addNumRange(begin, end ????) {


