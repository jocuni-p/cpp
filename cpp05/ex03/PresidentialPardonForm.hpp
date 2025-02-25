/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:45:54 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/02/25 15:17:28 by jocuni-p         ###   ########.fr       */
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
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& obj);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
	~PresidentialPardonForm();

	void execute(const Bureaucrat& executor) const; 
};
