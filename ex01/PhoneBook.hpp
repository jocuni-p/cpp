/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:01:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/22 12:08:53 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Contains the class definition (atributes and methods are declared here)

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>	// std::cout, std::cin, std::endl
#include <string>	// std::string
#include <iomanip>	// std::setw
#include <cstdlib>	// exit

class PhoneBook
{
private:
	Contact	contactList[8];
	int		counter;
public:
	PhoneBook();
	void	add();
	void	search();
	void	listprint();
};

#endif