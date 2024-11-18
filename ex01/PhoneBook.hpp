/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:01:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/18 17:15:23 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"
#include <iostream>// cout, cin
#include <string>//string
//Contiene la definicion de la class
//Aqui se declaran los metodos funciones, pero se define/implemnta su desarrollo en el .cpp

class PhoneBook
{
private:
	Contact	contactList[8]; //El array es de clase Contact y no Phonebook, porque contiene elementos clase Contact
	int		cnt;

public:
	PhoneBook();
	void	add();
	void	search();
	void	listprint();
};