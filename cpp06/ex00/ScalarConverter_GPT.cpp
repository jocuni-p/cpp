#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cmath>

void ScalarConverter::convert(const std::string &literal)
{
    char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;
    bool isChar = false, isInt = false, isFloat = false, isDouble = false;
/*
    // 📌 Manejo especial para pseudo-literales
    if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
        isFloat = true;
        f = std::strtof(literal.c_str(), NULL);
    } 
	else if (literal == "nan" || literal == "+inf" || literal == "-inf") {
        isDouble = true;
        d = std::strtod(literal.c_str(), NULL);
    } 
	
    // 📌 Detectar si es un char
e */if (literal.length() == 1 && !std::isdigit(literal[0])) {
        isChar = true;
        c = literal[0];
    } 
    // 📌 Detectar si es un número
//    else {
        char *end;
        d = std::strtod(literal.c_str(), &end);

        if ((*end == 'f' && *(end + 1) == '\0') || *end == '\0') {
            isDouble = true;
            isFloat = true;
            isInt = (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max() && !std::isnan(d));
            f = static_cast<float>(d);
//			i = static_cast<int>(d);
        } 
		// else if (*end == 'f' && *(end + 1) == '\0') {
        //     isFloat = true;
        //     isDouble = true;
        //     f = static_cast<float>(d);
        //     isInt = (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max() && !std::isnan(d));
        // }
//    }

    // 📌 Imprimir resultados
	//PRINT CHAR
    std::cout << "Char: ";
    if (isChar)
        std::cout << "'" << c << "'" << std::endl;
    else if (isInt && i >= 32 && i <= 126)
        std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
    else if (isInt)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "impossible" << std::endl;
	//PRINT INT
    std::cout << "Int: ";
    if (isInt)
//        std::cout << i << std::endl;
		std::cout << static_cast<int>(d) << std::endl; // ADDED BY ME
    else
        std::cout << "impossible" << std::endl;
	//PRINT FLOAT
    std::cout << "Float: ";
    if (isFloat)
        std::cout << f << (f == static_cast<int>(f) ? ".0f" : "f") << std::endl;
    else
        std::cout << "impossible" << std::endl;
	//PRNT DOUBLE
    std::cout << "Double: ";
    if (isDouble)
        std::cout << d << (d == static_cast<int>(d) ? ".0" : "") << std::endl;
    else
        std::cout << "impossible" << std::endl;
}
