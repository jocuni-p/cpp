/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:27:30 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/02/22 23:37:10 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*Default constructor*/
RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("Robotomy request", 72, 45), _target("Default_target") {
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
		throw NotGradeToExecuteException();
	std::cout << "\nDrilling noises..." << std::endl;
	// std::srand(std::time(0)); // Inicializa la semilla del generador de números aleatorios
	// if (std::rand() % 2 == 0) // Entra si el num aleatorio que genera rand() es par
	if (rand() % 2)// OPCION B
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed!" << std::endl;
}
