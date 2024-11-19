/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:01:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/19 17:12:54 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Contains the class definition (atributes and methods are declared here)

#pragma once

#include "Contact.hpp"
#include <iostream>// For std::cout std::cin
#include <string>//For std::string

class PhoneBook
{
private:
	Contact	contactList[8]; //Array de clase Contact y no PhoneBook, porque contiene elementos clase Contact
	int		cnt; //counts the contact' number

public:
	PhoneBook(); //Constructor, inicializes the private atribute 'cnt' to 0.
	//Deberia declarar un destructor ~PhoneBook() ???
	void	add();
	void	search();
	void	listprint(); //Prints the 'contactList' array
};