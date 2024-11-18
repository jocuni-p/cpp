/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:06:30 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/18 16:55:05 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"


void	PhoneBook::add() //Toda esta funcion trabaja dentro del ambito del objeto  la clase PhoneBook
{
	Declaro un objeto Contact aux;
	Declaro un string input;
	
	1:
	std::imprime "first name:"
	std::getline(cin, input)
	protector
	aux::setFirstName(input)
	
	2:
	imprime "second name:"
	getline(cin, input)
	protector
	aux::setSecondName(input)
	
	...

	5:
	imprime "dark secret:"
	getline(cin, input)
	protector
	setDarkSecret(input)
	
	Array_de_contacts[qty%8] = aux;
	qty++; //hace referencia al atributo qty de la clase 

	
}