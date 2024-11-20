/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:06:30 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/20 13:45:20 by jocuni-p         ###   ########.fr       */
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

	std::cout << "Let's create a new contact." << std::endl;
	do
	{
		std::cout << "Introduce a valid first name (avoid spaces/tabs before your input):" << std::endl;
		if (!std::getline(std::cin, input))// protection
			exit (1); //Quizas es abrupto salir con exit porque no se ejecutan los Destructores para limpiar las memorias ???
	} while (input == "" || input[0] == ' ' || input[0] == '	');// mientras sea un string vacio, un espacio o tabulador. Provar si funciona bien!!!!!!
	aux.setFirstName(input); //OJO, notese que usamos el . para ir a la funcion. Debe ir precedido de su Clase?
	
	do
	{
		std::cout << "Last name:" << std::endl;
		if (!std::getline(std::cin, input))
			exit (1);
	} while (input == "" || input[0] == ' ' || input[0] == '	');
	aux.setLastName(input);

	do
		{
			std::cout << "Nick name:" << std::endl;
			if (!std::getline(std::cin, input))
				exit (1);
		} while (input == "" || input[0] == ' ' || input[0] == '	');
		aux.setNickName(input);

	do
		{
			std::cout << "Phone number:" << std::endl;
			if (!std::getline(std::cin, input))
				exit (1);
		} while (input == "" || input[0] == ' ' || input[0] == '	');
		aux.setPhone(input);

	do
	{
		std::cout << "Dark secret:" << std::endl;
		if (!std::getline(std::cin, input))
			exit (1);
	} while (input == "" || input[0] == ' ' || input[0] == '	');
	aux.setDarkSecret(input);

	contactList[counter % 8] = aux; //Overwrites the last setted element
	counter++; //Updates the element/contact number 
}

void	PhoneBook::search()
{
	int	index;
	
	listprint();
	do
	{
		std::cout << "What index do you want to display (0-7)?" << std::endl;
		index = atoi(std::cin);
		if (index >= 0 && index <= 7)
		{
			std::cout << "First name: " contactList[index]::getFirstName << std::endl;
			std::cout << "Last name: " << contactList[index]::getLastName << std::endl;
			std::cout << "Nick name: " << contactList[index]::getNickName << std::endl;
			std::cout << "Phone number: " << contactList[index]::getPhone << std::endl;
			std::cout << "Dark secret: " << contactList[index]::getDarkSecret << std::endl;
		}
		else
			std::cout << "Invalid option" << std::endl;
			
	} while (index < 0 || index > 7);

}
void	PhoneBook::listprint()
{
	imprime el listado del PhoneBook en el formato definido por subject
}