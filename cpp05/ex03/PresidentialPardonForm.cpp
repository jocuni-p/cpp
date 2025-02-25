/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:46:03 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/02/25 15:17:37 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*Default constructor*/
PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("Default Presidential pardon", 25, 5), _target("Default_target") {
}

/* Constructor parametrizado */
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
	: AForm("Presidential pardon", 25, 5), _target(target) { 
}

/* Constructor de copia */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) 
	: AForm(obj), _target(obj._target) {}

/* Operador de asignacion de copia*/	
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
	if (this != &obj) {
		AForm::operator=(obj);
		_target = obj._target; 
	}
	return *this;
}

/*Destroyer*/
PresidentialPardonForm::~PresidentialPardonForm() {}


void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	std::cout << "\"" << _target << "\" has been pardoned by Zaphod Beeblebrox.\n" 
	<< std::endl;
}
