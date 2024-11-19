/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:13:55 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/19 17:02:56 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook; //Instancio un objeto de clase Phonebook
	std::string input;
	
	while (true)
	{
		std::cout << "Please, choose an option to continue ( add / search / exit ):" << std::endl;

		if (!std::getline(std::cin, input))// proteccion por error lectura o EOF
		{
			std::cerr << "Error on 'std::getline'. Exiting program." << std::endl;
			return 1;
		}	
		else if (input == "add")
			phonebook.add(); //LLamo al metodo add de mi objeto phonebook
		else if (input == "search")
			phonebook.search();//LLamo al metodo search de mi objeto phonebook
		else if (input == "exit")
		{
			std::cout << "'phonebook' was closed properly!" << std::endl;
			return 0;
		}
		else
		 std::cout << "Invalid command. Please, try again!" << std::endl;
	}
	return 0; //aunque nunca se alcanza este punto, debo mantener esta linea por el standard C++98
}
