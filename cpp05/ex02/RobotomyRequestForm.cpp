/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:27:30 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/02/24 11:30:36 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*Default constructor*/
RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("Default Robotomy request", 72, 45), _target("Default_target") {
}

/* Constructor parametrizado */
//llama al const parametrizado de su clase base con los parametros fijos 
//y inicializa target
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
	: AForm("Robotomy request", 72, 45), _target(target) { 
}

/* Constructor de copia */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) 
	: AForm(obj), _target(obj._target) {}

/* Operador de asignacion de copia*/	
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) {
	if (this != &obj) {
		AForm::operator=(obj);
		_target = obj._target;
	}
	return *this;
}

/*Destroyer*/
RobotomyRequestForm::~RobotomyRequestForm() {}


void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	std::srand(std::time(0)); // Inicializa la semilla del generador de números aleatorios
	if (std::rand() % 2 == 0) {// Entra si el num aleatorio que genera rand() es par
		std::cout << "Drilling noises... \"" << _target << "\"" 
		<< " has been robotomized successfully!\n" << std::endl;
	}
	else
		std::cout << "\"" << _target << "\" Robotomy failed!\n" << std::endl;
}
