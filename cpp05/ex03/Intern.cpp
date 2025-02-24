/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:29:15 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/02/24 17:46:51 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp";


Intern::Intern() {}

Intern::Intern(const Intern& copy) {
	*this = copy;
}

Intern& Intern::operator=(const Intern& obj) {
	(void)obj; // No copia nada porque en Intern no hay atributos
	return *this;
}


/*--Funciones auxiliares--*/
//Estas funciones no estan en Intern.hpp porque solo son usadas dentro de makeForm() 
//y no deberían estar accesibles fuera de Intern.cpp
AForm* createShrubbery(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm* createPresidential(std::string target) {
	return new PresidentialPardonForm(target);
}


AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	std::string formNames[3] = {
			"Shrubbery creation",
			"Robotomy request",
			"Presidential pardon"
	};

	AForm* (*formCreators[3])(std::string) = {
								createShrubbery,
								createRobotomy, 
								createPresidential
	};

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return formCreators[i](target);
		}
	}
	std::cerr << "Error: Form '" << formName << "' not found." << std::endl;
    return NULL;
}

	