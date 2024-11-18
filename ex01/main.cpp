/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:13:55 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/18 17:03:45 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

int main()
{
	Phonebook phonebook; //Instancio un objeto de clase Phonebook
	std::string input;
	
//	do
	while (42)
	{
	std::cout << "Choose an option to continue:" << std::endl;
	std::cout << "add" << std::endl;
	std::cout << "search" << std::endl;
	std::cout << "exit" << std::endl;
	//uso la funcion getline de la libreria std
	if (!std::getline(std::cin, input))// proteccion por si falla
		exit(1);
	if (input == "add")
		phonebook.add(); //LLamo al metodo add de mi objeto phonebook
	
/*		funcion que crea y guarda un contact(setea un nuevo objeto Contact)
		{
			std::cout << "first name:";
			_name = cin;
			std::cout << "last name:";
			...
			if (todos los campos llenos)
				 anyadir el objeto como un elemento del array PhoneBook		
		}*/
			
	if (input == "search")
		phonebook.search();//LLamo al metodo search de mi objeto phonebook
		
	if (input == "exit")
		exit(0);
//	} while (42);
	}
	return (0);
}