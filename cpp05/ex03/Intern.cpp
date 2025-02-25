/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:29:15 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/02/25 15:27:06 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern() {}

Intern::Intern(const Intern& copy) { // No attributes to copy
	*this = copy;
}

Intern& Intern::operator=(const Intern& obj) {
	(void)obj; // No copia nada porque en Intern no hay atributos
	return *this;
}

Intern::~Intern() {}


/*====Funciones auxiliares====*/
//Estas funciones no estan en Intern.hpp porque solo son usadas dentro de makeForm() 
//y no deberían estar accesibles fuera de Intern.cpp
AForm* createShrubbery(std::string target) {
	return new ShrubberyCreationForm(target); //Attention with memory leaks
}

AForm* createRobotomy(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm* createPresidential(std::string target) {
	return new PresidentialPardonForm(target);
}


AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	std::string formNames[3] = { // Array de nombre de los forms existentes
			"Shrubbery creation",
			"Robotomy request",
			"Presidential pardon"
	};

	AForm* (*formCreators[3])(std::string) = { // Array de funciones que crean forms
								createShrubbery,
								createRobotomy, 
								createPresidential
	};

	for (int i = 0; i < 3; i++) { // recorre los arrays
		if (formName == formNames[i]) { // busca el 'name' del form
			std::cout << "Intern creates a \"" << formName 
			<< "\" form for \"" << target << "\"" << std::endl << std::endl;
			return formCreators[i](target); // llama a la funcion que creara el form adecuado y inicializa su target
		}
	}
	std::cerr << "Error: \"" << formName << "\" not found and won't be created." << std::endl;
    return NULL; // en caso que no exista el formName pasado como parametro
}
