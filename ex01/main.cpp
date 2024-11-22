/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:13:55 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/22 12:21:00 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook; //Instances a Phonebook class object
	std::string input;
	
	std::cout << std::endl <<"\t=================" << std::endl;
	std::cout <<"\t*** PhoneBook ***" << std::endl;
	std::cout <<"\t=================" << std::endl << std::endl;
	while (true)
	{
		std::cout << "Please, choose an option to continue ( ADD / SEARCH / EXIT ): ";
		if (!std::getline(std::cin, input)) // protection in case wrong read or EOF
		{
			std::cerr << std::endl << "Error: Failed to read input using 'std::getline'" << std::endl;
			std::cout << "Exited properly." << std::endl;
			return 1;
		}	
		else if (input == "ADD")
			phonebook.add(); // Calling to the method 'add' from the 'phonebook' object
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT")
		{
			std::cout << std::endl << "The PhoneBook was closed properly!" << std::endl;
			return 0;
		}
		else
		 std::cout << "Invalid command. Please, try again!" << std::endl;
	}
	return 0; // Despite never arrives here it is mandatory by the C++98 standard
}
