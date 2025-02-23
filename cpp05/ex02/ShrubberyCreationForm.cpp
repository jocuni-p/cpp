/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:45:30 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/02/23 13:45:34 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*Default constructor*/
ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("Default Shrubbery creation", 145, 137), _target("Default_target") {
}

/* Constructor parametrizado */
//llama al const parametrizado de su clase base y inicializa target
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
	: AForm("Shrubbery creation", 145, 137), _target(target) { 
}

/* Constructor de copia */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) 
	: AForm(obj), _target(obj._target) {}

/* Operador de asignacion de copia*/	
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) {
	if (this != &obj) {
		AForm::operator=(obj);
		_target = obj._target;
	}
	return *this;
}

/*Destroyer*/
ShrubberyCreationForm::~ShrubberyCreationForm() {}


void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	std::ofstream file((_target + "_shrubbery").c_str()); //crea un archivo
    if (file.is_open()) { //abre el archivo
        file << "       _-_\n" // escribe en el archivo
             << "    /~~   ~~\\\n"
             << " /~~         ~~\\\n"
             << "{               }\n"
             << " \\  _-     -_  /\n"
             << "   ~  \\\\ //  ~\n"
             << "_- -   | | _- _\n"
             << "  _ -  | |   -_\n"
             << "      // \\\\\n";
        file.close(); // cierra el archivo
    } else {
        std::cerr << "Error: Could not open file." << std::endl;
    }
}
