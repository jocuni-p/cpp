/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:54:13 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/26 17:59:01 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include <string>
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]){

	if (argc != 2) {
		std::cerr << "Error: could not open file" << std::endl;
		std::cout << "Usage: ./btc <inputfile.txt>" << std::endl;
		return 1;
	}
	(void)argv[1];
	
	BitcoinExchange btc;

	try {

		btc.loadData("data.csv");
		btc.processInput(argv[1]);
//		btc.printRate("2022-02-20");
	}
	catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
	}

	return 0;
}