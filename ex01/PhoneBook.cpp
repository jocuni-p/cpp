/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:06:30 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/16 19:30:50 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int main()
{
	presentar el menu de arranque, con los 3 comandos posibles
	std::cout << "EXIT" << std::endl;
	"SEARCH"
	"ADD"
	
	while (bucle infinito)
	{
	espera un input que recoge con 'cin'
	if(input == "ADD")
		funcion que crea y guarda un contact(setea un nuevo objeto Contact)
		{
			std::cout << "first name:" ;
			_name = cin;
			std::cout << "last name:" ;
			...
			if (todos los campos llenos)
				 anyadir el objeto como un elemento del array PhoneBook		
		}
			
	if(input == "SEARCH")
		ir a funcion que busca un contacto
	if ("EXIT")
		se liberan memorias si hace falta y sale del programa rompiendo el bucle
	}
	return (0);
}
