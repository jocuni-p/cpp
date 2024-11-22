/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:06:30 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/22 12:19:13 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Here the class' methods are implemented/developed

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	counter = 0;	
}

//This function only works inside the scope of 'phonebook' object from PhoneBook class
void	PhoneBook::add()
{
	Contact		aux;
	std::string	input;
	
	do
	{
		std::cout << std::endl 
			<< "Introduce the first name (avoid spaces/tabs before your input): " 
			<< std::endl;
		if (!std::getline(std::cin, input))
			exit (1);
	} while (input == "" || input[0] == ' ' || input[0] == '	');
	aux.setFirstName(input);//Notice we use '.' to acces the method.
	do
	{
		std::cout << std::endl << "Introduce the last name: " << std::endl;
		if (!std::getline(std::cin, input))
			exit (1);
	} while (input == "" || input[0] == ' ' || input[0] == '	');
	aux.setLastName(input);
	do
	{
		std::cout << std::endl << "Introduce the nick name: " << std::endl;;
		if (!std::getline(std::cin, input))
			exit (1);
	} while (input == "" || input[0] == ' ' || input[0] == '	');
	aux.setNickName(input);
	do
	{
		std::cout << std::endl << "Introduce de phone number: " << std::endl;
		if (!std::getline(std::cin, input))
			exit (1);
	} while (input == "" || input[0] == ' ' || input[0] == '	');
	aux.setPhone(input);
	do
	{
		std::cout << std::endl << "Introduce a dark secret: " << std::endl << std::endl;
		if (!std::getline(std::cin, input))
			exit (1);
	} while (input == "" || input[0] == ' ' || input[0] == '	');
	aux.setDarkSecret(input);
	contactList[counter % 8] = aux; // Overwrites the last setted element
	counter++; // Updates the array element number
}


void	PhoneBook::search()
{
	std::string	input;
	int			index;
	
	listprint();
	while (true)
	{
		std::cout << std::endl << "What index do you want to display (0-7)? " 
			<< std::endl;
		if (!std::getline(std::cin, input))
				exit (1);
		index = atoi(input.c_str()); // c_str converts a 'std::string' to a 'char*'
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
	}
}

void	PhoneBook::listprint()
{
	int	i;

	i = 0;
	std::cout << std::endl;
	std::cout << std::setw(11) << "Index|" << "First name|" 
								<< std::setw(11) << "Last name|" 
								<< std::setw(11) << "Nick name|" << std::endl;
	std::cout << "----------|----------|----------|----------|" << std::endl;
	while (i <= 7)
	{
		std::cout << std::setw(10) << i << "|";
		if (contactList[i].getFirstName().length() > 10)
			std::cout << contactList[i].getFirstName().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << contactList[i].getFirstName().substr(0, 10) << "|";
		if (contactList[i].getLastName().length() > 10)
			std::cout << contactList[i].getLastName().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << contactList[i].getLastName().substr(0, 10) << "|";
		if (contactList[i].getNickName().length() > 10)
			std::cout << contactList[i].getNickName().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << contactList[i].getNickName().substr(0, 10) << "|";
		std::cout << std::endl;
		i++;
	}
}
