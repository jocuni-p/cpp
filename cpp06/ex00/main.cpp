#include <iostream>
#include <cstdlib> // para EXIT_FAILURE
#include "ScalarConverter.hpp"


int main(int argc, char **argv) {
	if (argc == 2 && argv[1][0] != '\0')
		ScalarConverter::convert(argv[1]);
	else {
		std::cout << "Error: missing argument" << std::endl;
		std::cout << "Correct use: ./ex00 <argument>" << std::endl; 
		return EXIT_FAILURE;
	}
	return 0;
}