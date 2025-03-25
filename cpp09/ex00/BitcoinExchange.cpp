/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:05:42 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/25 19:28:54 by jocuni-p         ###   ########.fr       */
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
	
	//CHECK APERTURA FILE CSV
	std::ifstream file(filename.c_str()); // pasa 'string' a char *str 
	if (!file || file.fail()) { // in case open fails or file does not exist
		// std::cerr << "Error. Open 'file.csv' failure." << std::endl;
		// std::exit (1);
		throw std::runtime_error("Error: Open 'file.csv' failed '" + filename + "'");
	}

	std::string line;
	std::string date;
	float value;
	
	//CARGA DEL CSV AL MAPA
	std::getline(file, line); // Lee la primera linea sin informacion para map
	
	while (std::getline(file, line)){
		std::stringstream ss(line);
		if (!std::getline(ss, date, ',') || !(ss >> value)){// pongo fecha en 'date' y el resto casteado a float en 'value'.
			std::cerr << "Error: Invalid line in database" << std::endl;
			continue;
		}

		//VALIDACION FECHA
		if (!isDateValid(date)){
			std::cout << "Error: Date is not valid" << std::endl;
			continue;
		}
		
		_BtcExchange[date] = value; // upload the value into the map container
	}

//	file.close(); // No estoy seguro si lo necesita
}


//void BitcoinExchange::processInput(const std::string& filename) {

	// usar isDateValid para chequear fecha
	// check value isdigit()
	// check que value es un float o int entre 0 y 1000 "Error: Value is not a valid range"
//}




/* lower_bound() encuentra un elemento igual o suprior a date*/
float BitcoinExchange::getRate(const std::string& date) {

	std::map<std::string, float>::iterator it = _BtcExchange.lower_bound(date);
	
	//Si llego al final o encontro una fecha distinta a date retrocedemos a un elemento anterior (menor) 
	if (it == _BtcExchange.end() || (it != _BtcExchange.begin() && it->first != date)) {
		--it;
	}
	
	//Si encontro la fecha exacta retornamos su valor
	if (it != _BtcExchange.end()) {
		return it->second;
	}
	return -1;
}



//SOLO PER PROBAR IMPRIMIR //////ELIMINAR????????????/
void BitcoinExchange::printRate(const std::string& date) {
	for (std::map<std::string, float>::iterator it = _BtcExchange.begin(); it->first != date; ++it)
		std::cout << it->second << std::endl;
}



/* Validates if date exist and its format is correct*/
/* Takes into account the leap years as well (leap year is % 4, if ends xx00 and % 400)*/
bool BitcoinExchange::isDateValid(const std::string& date) {
	
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') return false;
	for (size_t i = 0; i < date.size(); ++i)
	{
		if ((i != 4 && i != 7) && !isdigit(date[i])) return false;
	}

	int year;
	int month;
	int day;
	char sign1;
	char sign2;

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
