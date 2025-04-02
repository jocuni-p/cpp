/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 13:01:21 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/31 15:37:34 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"

int main(int argc, char **argv) {
	
	if (argc != 2) {
		std::cerr << "Error: Incorrect number of arguments." << std::endl;
		std::cout << "Usage: ./RPN <\"3 5 + 9 -...\"" << std::endl;
		return 1;
	}

	RPN myRpn;
	
	
	try {
		std::string input = argv[1];

		std::cout << "Input: " << input << std::endl;
		std::cout << myRpn.calculation(input) << std::endl;
	}
	catch(std::exception& e) {
		std::cerr << e.what() << std::endl; // aporta un error explicito
	}

	return 0;
}
