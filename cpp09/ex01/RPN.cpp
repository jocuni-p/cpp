/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 13:31:08 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/31 16:31:22 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& copy) : _stackRPN(copy._stackRPN) {}

RPN& RPN::operator=(const RPN& obj) {
	if (this != &obj)
		_stackRPN = obj._stackRPN;
	return *this;
}

RPN::~RPN() {}


int RPN::calculation(const std::string& input) {
	if (input.empty())  
    	throw std::runtime_error("Error: Empty expression.");

	if (input.find_first_not_of("0123456789 +-*/") != std::string::npos)
		throw std::invalid_argument("Error: Input contains invalid characters.");

	std::stringstream ss(input);
	std::string token;

	while (ss >> token) { // mientras haya algo en el flujo
		
		if (token.size() == 1 && isdigit(token[0])) {
			int num = token[0] - '0'; // lo convierto a entero
			_stackRPN.push(num); // lo subo al stack
		}
		
		else if (token == "+" || token == "-" || token == "*" || token == "/") {
			if (_stackRPN.size() < 2) //quizas seria mejor != 2  ???
				throw std::runtime_error("Error: Invalid expression found.");

			int b = _stackRPN.top(); _stackRPN.pop();
			int a = _stackRPN.top(); _stackRPN.pop();
			
			if (token == "+") _stackRPN.push(a + b);
			else if (token == "-") _stackRPN.push(a - b);
			else if (token == "*") _stackRPN.push(a * b);
			else if (token == "/"){
				if (b == 0)
					throw std::runtime_error("Error: found a division by 0.");
				_stackRPN.push(a / b);
			}		
		}
		else {
			throw std::runtime_error("Error: bad input expression.");
		}
	}
	
	if (_stackRPN.size() != 1)
		throw std::runtime_error("Error: Invalid expression found.");
	return _stackRPN.top();
}
