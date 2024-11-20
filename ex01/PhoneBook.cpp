/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:06:30 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/20 18:24:48 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Here the class' methods are implemented/developed
#include "PhoneBook.hpp"
#include "Contact.hpp"


PhoneBook::PhoneBook() //The constructor inicializes an atribute
{
	counter = 0;	
}

void	PhoneBook::add() //Toda esta funcion trabaja dentro del ambito del objeto  la clase PhoneBook
{
	Contact		aux;
	std::string	input;
	
//	std::cout << std::endl <<"\t*** PhoneBook ***" << std::endl << std::endl;
//	std::cout << "Let's create a new contact." << std::endl;
	do
	{
		std::cout << std::endl 
			<< "Introduce a valid first name (avoid spaces/tabs before your input):" 
			<< std::endl << std::endl;
		if (!std::getline(std::cin, input))// protection
			exit (1); //Quizas es abrupto salir con exit porque no se ejecutan los Destructores para limpiar las memorias ???
	} while (input == "" || input[0] == ' ' || input[0] == '	');// mientras sea un string vacio, un espacio o tabulador. Provar si funciona bien!!!!!!
	aux.setFirstName(input); //OJO, notese que usamos el . para ir a la funcion. Debe ir precedido de su Clase?
	
	do
	{
		std::cout << std::endl << "Last name:" << std::endl << std::endl;
		if (!std::getline(std::cin, input))
			exit (1);
	} while (input == "" || input[0] == ' ' || input[0] == '	');
	aux.setLastName(input);

	do
	{
		std::cout << std::endl << "Nick name:" << std::endl << std::endl;
		if (!std::getline(std::cin, input))
			exit (1);
	} while (input == "" || input[0] == ' ' || input[0] == '	');
	aux.setNickName(input);

	do
	{
		std::cout << std::endl << "Phone number:" << std::endl << std::endl;
		if (!std::getline(std::cin, input))
			exit (1);
	} while (input == "" || input[0] == ' ' || input[0] == '	');
	aux.setPhone(input);

	do
	{
		std::cout << std::endl << "Dark secret:" << std::endl << std::endl;
		if (!std::getline(std::cin, input))
			exit (1);
	} while (input == "" || input[0] == ' ' || input[0] == '	');
	aux.setDarkSecret(input);

	contactList[counter % 8] = aux; //Overwrites the last setted element
	counter++; //Updates the element/contact number 
}

void	PhoneBook::search()
{
	std::string	input;
	int			index;
	
	listprint();
	while (true)
	{
		std::cout << std::endl << "What index do you want to display (0-7)?" << std::endl;
		if (!std::getline(std::cin, input)) //Recojo el valor
				exit (1);// protection
		
		index = atoi(input.c_str());//c_str converts a 'std::string' to a 'char*'
		
		if (input.length() == 1 && std::isdigit(input[0]) && index >= 0 && index <= 7)
		{
			std::cout << std::endl 
				<< "First name:\t " << contactList[index].getFirstName() << std::endl
				<< "Last name:\t " << contactList[index].getLastName() << std::endl
				<< "Nick name:\t " << contactList[index].getNickName() << std::endl
				<< "Phone number:\t " << contactList[index].getPhone() << std::endl
				<< "Dark secret:\t " << contactList[index].getDarkSecret() << std::endl 
				<< std::endl;
			break;
		}
		else
			std::cout << "Invalid option" << std::endl;
			
	}//while (index < 0 || index > 7);
}

void	PhoneBook::listprint()
{
	int	i;

	i = 0;
	std::cout << std::endl;
	std::cout << std::setw(10) << "Index|" << std::setw(10) 
								<< "First name|" 
								<< "Last name|" 
								<< "Nick name|" << std::endl;
	std::cout << "----------|----------|----------|----------|" << std::endl;
	
	
	std::cout << std::setw(10) << i << "|" << i << "|" << std::endl;
	
}