/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:15:43 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/02 21:56:39 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib> // para EXIT_FAILURE
#include "ScalarConverter.hpp"

/*
int main(int argc, char **argv) {
	if (argc == 2 && argv[1][0] != '\0')
		ScalarConverter::convert(argv[1]);
	else {
		std::cout << "Error: missing correct argument" << std::endl;
		std::cout << "Expected use: ./ex00 <argument>" << std::endl; 
		return EXIT_FAILURE;
	}
	return 0;
}
*/

int main(void) {
	std::string c = "c";
	std::string i = "42";
	std::string f = "42.42f";
	std::string d = "42.800";
	
	std::cout << "./convert " << c << std::endl;
	ScalarConverter::convert(c);
	std::cout << "----------" << std::endl;
	std::cout << "./convert " << i << std::endl;
	ScalarConverter::convert(i);	
	std::cout << "----------" << std::endl;
	std::cout << "./convert " << f << std::endl;
	ScalarConverter::convert(f);
	std::cout << "----------" << std::endl;
	std::cout << "./convert " << d << std::endl;
	ScalarConverter::convert(d);	
	std::cout << "----------" << std::endl;
	std::cout << "./convert " << "nan" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << "----------" << std::endl;
	std::cout << "./convert " << "-inff" << std::endl;
	ScalarConverter::convert("-inff");	
	std::cout << "----------" << std::endl;
	std::cout << "./convert " << "13" << std::endl;
	ScalarConverter::convert("13");
	std::cout << "----------" << std::endl;
	std::cout << "./convert " << "299" << std::endl;
	ScalarConverter::convert("299");	
	std::cout << "----------" << std::endl;
	std::cout << "./convert " << "-782364686.23" << std::endl;
	ScalarConverter::convert("-782364686.23");
	std::cout << "----------" << std::endl;
	std::cout << "./convert " << "-234.34f" << std::endl;
	ScalarConverter::convert("-234.34f");	
	std::cout << "----------" << std::endl;
	std::cout << "./convert " << "123hola" << std::endl;
	ScalarConverter::convert("123hola");	
	std::cout << "----------" << std::endl;
	std::cout << "./convert " << "934793745982829535985629836398347097228798547323753092742493787202875527.5" << std::endl;
	ScalarConverter::convert("934793745982829535985629836398347097228798547323753092742493787202875527.5");	
	std::cout << "----------" << std::endl;
	
	return 0;
	
}

