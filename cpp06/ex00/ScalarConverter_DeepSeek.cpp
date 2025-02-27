#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <iomanip>

void ScalarConverter::convert(const std::string &literal)
{
    char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;
    bool isChar = false, isInt = false, isFloat = false, isDouble = false;

    // Check for special cases: inf, -inf, nan
    if (literal == "inf" || literal == "+inf" || literal == "-inf" || literal == "nan" ||
        literal == "inff" || literal == "+inff" || literal == "-inff" || literal == "nanf")
    {
        isFloat = true;
        isDouble = true;
        if (literal == "inff" || literal == "+inff" || literal == "-inff" || literal == "nanf")
            f = std::strtof(literal.c_str(), NULL);
        else
            d = std::strtod(literal.c_str(), NULL);
    }
    else if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
        // Handle char case
        isChar = true;
        c = literal[0];
    }
    else
    {
        // Handle int, float, and double cases
        char *end;
        d = std::strtod(literal.c_str(), &end);

        if (*end == 'f' && *(end + 1) == '\0')
        {
            isFloat = true;
            f = static_cast<float>(d);
        }
        else if (*end == '\0')
        {
            isDouble = true;
            if (d == static_cast<int>(d))
                isInt = true;
        }

        if (isDouble && !std::isnan(d) && !std::isinf(d) &&
            d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
        {
            isInt = true;
            i = static_cast<int>(d);
        }
    }

    // Print char
    std::cout << "char: ";
    if (isChar)
    {
        if (std::isprint(c))
            std::cout << "'" << c << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
    else if (isInt && i >= 32 && i <= 126)
        std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "impossible" << std::endl;

    // Print int
    std::cout << "int: ";
    if (isInt)
        std::cout << i << std::endl;
    else
        std::cout << "impossible" << std::endl;

    // Print float
    std::cout << "float: ";
    if (isFloat || isDouble)
    {
        if (isFloat)
            std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        else
            std::cout << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;

    // Print double
    std::cout << "double: ";
    if (isDouble)
        std::cout << std::fixed << std::setprecision(1) << d << std::endl;
    else
        std::cout << "impossible" << std::endl;
}
