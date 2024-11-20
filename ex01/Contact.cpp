/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:06:13 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/20 14:42:52 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*----------Constructor------------*/

Contact::Contact(){} //instancia/crea un objeto de la clase Contact, pero sin inicializar sus atributos
//Al no definir comportamiento inicializa los 'string' a "" vacio y los 'int' con lo que contenga la memoria


/*-------setter' functions--------*/

void	Contact::setFirstName(std::string str)
{
	firstName = str;
}

void	Contact::setLastName(std::string str)
{
	lastName = str;
}
void	Contact::setNickName(std::string str)
{
	nickName = str;
}
void	Contact::setPhone(std::string str)
{
	phone = str;
}

void	Contact::setDarkSecret(std::string str)
{
	darkSecret = str;
}

/*-------getter' functions--------*/

std::string	Contact::getFirstName()
{
	return firstName;
}

std::string	Contact::getLastName()
{
	return lastName;
}

std::string	Contact::getNickName()
{
	return nickName;
}

std::string	Contact::getPhone()
{
	return phone;
}

std::string	Contact::getDarkSecret()
{
	return darkSecret;
}
