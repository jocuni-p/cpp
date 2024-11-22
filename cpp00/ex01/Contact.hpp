/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:03:56 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/22 12:06:25 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phone;
	std::string	darkSecret;
public:
	Contact();
	void	setFirstName(std::string);
	void	setLastName(std::string);
	void	setNickName(std::string);
	void	setPhone(std::string);
	void	setDarkSecret(std::string);
	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickName();
	std::string	getPhone();
	std::string	getDarkSecret();
};

#endif