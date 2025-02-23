/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:45:54 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/02/23 13:45:55 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	std::string	_target;
	
	public:
	PresidentialPardonForm(); // Default constructor
	PresidentialPardonForm(const std::string& target); // const parametrizado
	PresidentialPardonForm(const PresidentialPardonForm& obj); // const de copia
	PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
	~PresidentialPardonForm();

	void execute(const Bureaucrat& executor) const; 
};
