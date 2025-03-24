/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:05:42 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/24 13:27:45 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


/* Default constructor */
BitcoinExchange::BitcoinExchange() {}

/* Copy constructor */
BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
	*this = copy; // it calls to operator=
}

/* Assignment operator overload */
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj) {
	if (this != &obj)
		_BtcExchange = obj._BtcExchange;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

/* Member functions */
void loadData(const std::string& filename) {
	
	std::ifstream file("./data.csv");
	if (!file || file.fail()) { // in case open fails or file does not exist
		std::cerr << "Error. Open file.csv failure." << std::endl;
		return;
	}

	std::string line;
	std::string date;
	float value;

	while (std::getline(file, line)){
		std::stringstream ss(line);
		std::getline(ss, date, ',');
		ss >> value; // pongo el resto del stream en value y lo convierte a float
		if (!ss.fail())
		_BtcExchange[date] = value;
	}

//	al final del scope si no se cierre el archivo file, cerrarlo con file.close()
}

void processInput(const std::string& filename) {


	
}

float getRate(const std::string& date) {

	
	
}

bool isDateValid(const std::string& date) {


	
}