/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:15:02 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/06 12:58:29 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <limits> // check overflows
#include <cstdlib> // std::strtod
#include <cmath> // nan & inf
#include <iomanip> // std::fixed & setprecision

void ScalarConverter::convert(const std::string &literal)
{
    char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;
    bool isChar = false, isInt = false, isFloat = false;

	/*------CHECK FOR PSEUDO-LITERALS-----*/
	if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
		isFloat = true;
		f = static_cast<float>(std::strtod(literal.c_str(), NULL));
		d = static_cast<double>(f);
	} 
	else if (literal == "nan" || literal == "+inf" || literal == "-inf") {
		isFloat = true;
		d = std::strtod(literal.c_str(), NULL);
		f = static_cast<float>(d);
	} 
	
	/*---CHECK FOR JUST ONE PRINTABLE CHAR*/
	else if (literal.length() == 1 && !std::isdigit(literal[0])) {
		isChar = true;
		c = literal[0];
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);

		isInt = true;
		isFloat = true;
	} 

	/*-----CHECK FOR A NUMBER------*/
	else {
		char *end;
		d = std::strtod(literal.c_str(), &end);

		if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0')) {//IF IT IS A NON CONVERTIBLE INPUT
			std::cout << "Char: impossible" << std::endl;
			std::cout << "Int: impossible" << std::endl;
			std::cout << "Float: impossible" << std::endl;
			std::cout << "Double: impossible" << std::endl;
			return;
		}
		
		if (*end == '\0') {  // IF IS A NUM WITHOUT SUFIX
			isInt = (d >= std::numeric_limits<int>::min() &&
					 d <= std::numeric_limits<int>::max() &&
					 d == static_cast<int>(d) &&
					 !std::isnan(d) &&
					 !std::isinf(d));
			isFloat = true;
			f = static_cast<float>(d);
			i = static_cast<int>(d);
		}
		else if (*end == 'f' && *(end + 1) == '\0') {  // IF IT HAS 'f' AT THE END -> IS FLOAT
			isFloat = true;
			f = static_cast<float>(d);
			d = static_cast<double>(f);
			isInt = (d >= std::numeric_limits<int>::min()&&
					 d <= std::numeric_limits<int>::max() &&
					 d == static_cast<int>(d) && // OJO: se podrá convertir SOLO si no tiene decimales o es .0)
					 !std::isnan(d) &&
					 !std::isinf(d));
			i = static_cast<int>(d);
		}
	}

	/*-----FORMAT THE OUTPUT TO DECIMAL NOTATION-------*/
	//Evita notacion cientifica y establece precision en 1 decimal (si es el caso)
    std::cout << std::fixed << std::setprecision(1);

	/*--------PRINT CHAR---------*/
    std::cout << "Char: ";
    if (isChar) // if a char is the literal arg
        std::cout << "'" << c << "'" << std::endl;
    else if (isInt && i >= 32 && i <= 126) // if char conversion is printable
       	std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
    else if (isInt && ((i >= 0 && i <= 31) || i == 127)) // if char conversion is NOT printable
        std::cout << "Non displayable" << std::endl; // if char conversion is NOT printable
    else
        std::cout << "impossible" << std::endl; 
		
	/*----PRINT INT----*/
    std::cout << "Int: ";
    if (isInt)
        std::cout << i << std::endl;
    else
        std::cout << "impossible" << std::endl; 

	/*------PRINT FLOAT-------*/
    std::cout << "Float: ";
    if (isFloat)
		std::cout << f << "f" << std::endl;
    else
        std::cout << "impossible" << std::endl;

	/*-------PRNT DOUBLE--------*/
    std::cout << "Double: " << d << std::endl;
}

