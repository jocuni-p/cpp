/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:05:42 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/27 13:24:27 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


/*============= Canonical form =============*/

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



/*============= Member functions ==============*/

void BitcoinExchange::loadData(const std::string& filename) {
	
	//Open the input arg
	std::ifstream file(filename.c_str()); // it takes a char *str 
	if (!file || file.fail()) {
		throw std::runtime_error("Error: Open '" + filename + "' failure");
	}

	std::string line, date;
	float value;
	
	//CSV loading to the map
	std::getline(file, line); // Step over the first line
	
	while (std::getline(file, line)){
		std::stringstream ss(line);
		if (!std::getline(ss, date, ',') || !(ss >> value)){
			std::cerr << "Error: Invalid line in database" << std::endl;
			continue;
		}

		
		if (!isDateValid(date)){
			std::cout << "Error: Date is not valid" << std::endl;
			continue;
		}
		
		_BtcExchange[date] = value; // save the value into the map container
	}

	file.close();
}


void BitcoinExchange::processInput(const std::string& filename) {
	
	std::ifstream file(filename.c_str());
	if (!file || file.fail())
		throw std::runtime_error("Error: Open '" + filename + "' failure");

	std::string line;
	bool firstLine = true;
	
	while (std::getline(file, line)) { //gets the line if it exist
		if (firstLine){
			firstLine = false;
			if (line == "date | value") continue;
		}


		std::string date;
		char separator;
		std::string valueStr;
		float value;

		std::stringstream ss(line);
		ss >> date >> separator >> valueStr;
		
		if (ss.fail() || separator != '|'){
			std::cerr << "Error: bad input format => " << line << std::endl;
			continue;
		}

		if (!isDateValid(date)){
			std::cerr << "Error: bad input date => " << date << std::endl;
			continue;
		}

		if (valueStr[0] == '-'){
			std::cerr << "Error: not a positive value => " << valueStr << std::endl;
			continue;
		}
		
		std::stringstream valueSS(valueStr);
		valueSS >> value; // Save the flew to 'value'

		if (valueSS.fail() || valueStr.find_first_not_of("0123456789.") != std::string::npos ||
			std::count(valueStr.begin(), valueStr.end(), '.') > 1) {
			std::cerr << "Error: bad input value => " << valueStr << std::endl;
			continue;
		}

		//Sets 'cerr' to decimal notation and with 2 decimal digits
		std::cerr << std::fixed << std::setprecision(2);
		

			if (value < 0 || value > 1000)
			{
				std::cerr << "Error: out of range value(0-1000) => " << value << std::endl;
				continue;
		}

		float rate = getRate(date);
		
		//Sets 'cout' to decimal notation and with 2 decimal digits
		std::cout << std::fixed << std::setprecision(2);

		if (rate >= 0)
			std::cout << date << " => " << value << " = " << value * rate << std::endl;
		else
			std::cout << "Error: date previous to the database => " << date << std::endl;
		
	}
	file.close();
}


/* lower_bound() looks for an equal or higher key, otherwise returns end()  */
float BitcoinExchange::getRate(const std::string& date) {

	std::map<std::string, float>::iterator it = _BtcExchange.lower_bound(date);
	if (it == _BtcExchange.end() || (it != _BtcExchange.begin() && it->first != date)) {
//		if (it == _BtcExchange.begin())
		--it;
	}
	
	if (it != _BtcExchange.end()) {
		return it->second;
	}
	return -1;
}


/* Validates if the date and format are correct, taking into account the leap years */
bool BitcoinExchange::isDateValid(const std::string& date) {
	
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') return false;
	for (size_t i = 0; i < date.size(); ++i)
	{
		if ((i != 4 && i != 7) && !isdigit(date[i])) return false;
	}

	int year, month, day;
	char sign1, sign2;

	std::stringstream ss(date);
	ss >> year >> sign1 >> month >> sign2 >> day;

	if (ss.fail() || sign1 != '-' || sign2 != '-') return false;
	if (month < 1 || month > 12 || day < 1 || day > 31) return false;
	
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	//if it is a february and a leap year must have 29 days
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        daysInMonth[1] = 29;
    }

	//if the day fits into the number of days of that month returns 'true'
    return day <= daysInMonth[month - 1];
}
