/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:06:30 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/19 17:19:44 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Here the class' methods are implemented/developed
#include "PhoneBook.hpp"
#include "Contact.hpp"


PhoneBook::PhoneBook() //The constructor inicializes an atribute
{
	cnt = 0;	
}

void	PhoneBook::add() //Toda esta funcion trabaja dentro del ambito del objeto  la clase PhoneBook
{
	Contact		aux;
	std::string	input;

	std::cout << "Let's create a new contact." << std::endl;
	do
	{
		std::cout << "Introduce a valid first name:" << std::endl;
		
		if (!std::getline(std::cin, input))// protection
			exit (1); //Quizas es abrupto salir con exit porque no se ejecutan las Destructores para limpiar las memorias ???

	} while (input == "" || input[0] == ' ' || input[0] == '	');// mientras sea un string vacio, un espacio o tabulador. Provar si funciona bien!!!!!!
	
	aux.setFirstName(input); //OJO, notese que usamos el . para ir a la funcion
	
	2:
	imprime "Introduce the second name:"
	getline(cin, input)
	protector
	aux::setSecondName(input)
	
	...

	5:
	imprime "Introduce the dark secret:"
	getline(cin, input)
	protector
	setDarkSecret(input)
	
	Array_de_contacts[qty%8] = aux;
	qty++; //hace referencia al atributo qty de la clase 

	
}

void	PhoneBook::search()
{
	


	
}
void	PhoneBook::listprint()
{


	
}