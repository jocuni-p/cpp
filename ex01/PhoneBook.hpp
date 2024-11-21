/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:01:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/21 15:06:52 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Contains the class definition (atributes and methods are declared here)

#pragma once

#include "Contact.hpp"
#include <iostream>	// std::cout, std::cin, std::endl
#include <string>	// std::string
#include <iomanip>	// std::setw
#include <cstdlib>	// exit

class PhoneBook
{
private:
	Contact	contactList[8]; //Array of 'Contact' class, because contain class 'Contact' elements
	int		counter; //counts the array' elements number
public:
	PhoneBook(); //Constructor, inicializes the private atribute 'cnt' to 0.
	void	add();
	void	search();
	void	listprint(); //Prints the 'contactList' array
};