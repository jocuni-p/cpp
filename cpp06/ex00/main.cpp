/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:15:43 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/05 14:48:13 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib> // para EXIT_FAILURE
#include "ScalarConverter.hpp"


int main(int argc, char **argv) {
	if (argc == 2 && argv[1][0] != '\0')
		ScalarConverter::convert(argv[1]);
	else {
		std::cout << "Error: missing correct argument" << std::endl;
		std::cout << "Expected use: ./ex00 <argument>" << std::endl; 
		return EXIT_FAILURE;
	}
	
	std::cout << "\n=====================\n" << std::endl;
	
	float	f = 42.4f;

	std::cout << "float f = " << f << std::endl;
	std::cout << "static_cast<int>(f) = " << static_cast<int>(f) << std::endl;
	std::cout << "\nMakes an explicit conversion and truncates the fractional part of a float or double, " << std::endl;
	std::cout << "without rounding, which implies a loss of precision, especially in large numbers." << std::endl;
	std::cout << "We also have to take care of overflows (int limits)..\n" << std::endl;
	
	return 0;
}

