#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cmath>

void ScalarConverter::convert(const std::string& literal)
{
    char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;
    bool isChar = false, isInt = true, isFloat = false, isDouble = false;
	
	/*====DETECTAR SI ES CHAR=====*/

    if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
        isChar = true;
        // c = static_cast<char>(literal[0]);
        c = literal[0];
    }
    else // CREC QUE NO FA FALTA
		isChar = false; // CREC QUE NO FA FALTA

	/*=====DETECTAR SI ES NUMERO=====*/
    char *end;
	d = std::strtod(literal.c_str(), &end);
    if ((*end == 'f' && *(end + 1) == '\0') || *end == '\0')
    {
        isFloat = true;
        isDouble = true;
        isInt = true;
		f = static_cast<float>(d);
    }
    else
        isInt = false;

    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || std::isnan(d))
        isInt = false;
    else
        i = static_cast<int>(d);

    std::cout << "Char : ";
    if (isChar)
	{
        std::cout << "'" << c << "'";
        std::cout << "\nInt: " << static_cast<int>(c);
        std::cout << "\nFloat: " << static_cast<float>(c) << ".0f";
        std::cout << "\nDouble: " << static_cast<double>(c) << ".0" << std::endl;
	}
	else
	{
		if (isInt && i >= 32 && i <= 126)
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		else if (isInt && ((i >= 0 && i <= 31) || i == 127))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "impossible" << std::endl;
		
		std::cout << "Int : ";
		if (isInt)
			std::cout << i << std::endl;
		else
			std::cout << "impossible" << std::endl;

		std::cout << "Float : ";
		if (isFloat || isDouble)
			std::cout << f << (f == static_cast<int>(f) ? ".0f\n" : "f\n");
		else
			std::cout << "impossible" << std::endl;

		std::cout << "Double : ";
		if (isDouble)
			std::cout << d << (d == static_cast<int>(d) ? ".0\n" : "\n");
		else
			std::cout << "impossible" << std::endl;
	}

}












