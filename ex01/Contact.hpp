/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:03:56 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/18 14:36:02 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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