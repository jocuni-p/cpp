/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:05:42 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/23 20:36:13 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* Default constructor */
BitcoinExchange::BitcoinExchange() {}

/* Copy constructor */
BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
	*this = copy; // we call to operator=
}

/* Assignment operator overload */
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj) {
	if (this != &obj)
		_BtcExchange = obj._BtcExchange;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

/* Member functions */
void loadCSV(const std::string& filename) {


	
}

void processInput(const std::string& filename) {


	
}

float getRate(const std::string& date) {

	
	
}

bool isDateValid(const std::string& date) {


	
}