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
    bool isChar = false, isInt = false, isFloat = false, isDouble = false;

	/*------CHECKS FOR PSEUDO-LITERALS-----*/
	if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
		isFloat = true;
		isDouble = true;
		f = std::strtof(literal.c_str(), NULL);
		d = static_cast<double>(f);
	} 
	else if (literal == "nan" || literal == "+inf" || literal == "-inf") {
		isDouble = true;
		isFloat = true;
		d = std::strtod(literal.c_str(), NULL);
		f = static_cast<float>(d);
	} 
	
    /*------CHECKS FOR CHAR-------*/
	// else if (literal.length() == 1 && !std::isdigit(literal[0])) {
    //     isChar = true;
    //     c = literal[0];
    // }

	/*---CHECKS FOR ONLY ONE PRINTABLE CHARACTER*/
	else if (literal.length() == 1 && !std::isdigit(literal[0])) {
		isChar = true;
		c = literal[0];
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	} 


    /*-----CHECKS FOR NUM-----*/
	// else if {
	// 	char *end;
	// 	d = std::strtod(literal.c_str(), &end);

	// 	if ((*end == 'f' && *(end + 1) == '\0') || *end == '\0') {
	// 		isDouble = true;
	// 		isFloat = true;
	// 		isInt = (d >= std::numeric_limits<int>::min() 
	// 				&& d <= std::numeric_limits<int>::max() 
	// 				&& !std::isnan(d) && !std::isinf(d)); // AQUI TENGO DUDAS
	// 		if (isInt)
	// 			i = static_cast<int>(d);
	// 		f = static_cast<float>(d);
	// 	} 
	// }

	/*-----CHECKS FOR A NUMBER------*/
	else {
		char *end;
		d = std::strtod(literal.c_str(), &end);

		if (*end == '\0') {  // IS A NUM WITHOUT SUFIX
			isDouble = true;
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
			isDouble = true;
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
    std::cout << std::fixed << std::setprecision(1); // the subject shows just 1 decimal

	/*--------PRINT CHAR---------*/
    std::cout << "Char: ";
    if (isChar) // if a char is the literal arg
        std::cout << "'" << c << "'" << std::endl;
    else if (isInt && i >= 32 && i <= 126) // if char conversion is printable
       	std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
    else if (isInt && ((i >= 0 && i <= 31) || i == 127)) // if char conversion is NOT printable
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "impossible" << std::endl; // not convertible or wrong arg

	/*----PRINT INT----*/
    std::cout << "Int: ";
    if (isInt)
        std::cout << i << std::endl;
    else
        std::cout << "impossible" << std::endl; // not convertible or wrong arg

	/*------PRINT FLOAT-------*/
    std::cout << "Float: ";
    if (isFloat)
		std::cout << f << "f" << std::endl;
    else
        std::cout << "impossible" << std::endl; // not convertible or wrong arg

	/*-------PRNT DOUBLE--------*/
    std::cout << "Double: ";
    if (isDouble)
        std::cout << d << (d == static_cast<int>(d) ? ".0" : "") << std::endl;
    else
        std::cout << "impossible" << std::endl; // not convertible or wrong arg
}
