/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:30:42 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/02/25 14:38:59 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*Default constructor*/
Bureaucrat::Bureaucrat() : _name("Default"), _grade(42) {}

/* Constructor parametrizado */
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	if (_grade < 1) // Exception in out of range case!!!
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

/* Constructor de copia */
Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name), _grade(obj._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
	if (this != &obj) {
	// name es const y no se puede re-asignar de nuevo
		_grade = obj._grade;
	}
	return *this;
}

const std::string& Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }


void Bureaucrat::incrementGrade() {
	if (_grade == 1) // Creamos nuestra excepcion
	  	throw GradeTooHighException();
	else
		_grade -= 1;
}

void Bureaucrat::decrementGrade() { 
	 if (_grade == 150) // Creamos otra excepcion
		throw GradeTooLowException();
	else
		_grade += 1;
}


const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}


/*----------------Insertion operator overload------------------*/
std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj) {
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return out;
}

