/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:40:55 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/02/25 14:40:57 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*Default constructor*/
Bureaucrat::Bureaucrat() : _name("Default_Bureaucrat"), _grade(10) {}

/* Constructor parametrizado */
Bureaucrat::Bureaucrat(const std::string name, int grade) 
	: _name(name), _grade(grade) {
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

/* Constructor de copia */
Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name), _grade(obj._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
	if (this != &obj) {
	// _name es const y no se puede re-asignar de nuevo
		_grade = obj._grade;
	}
	return *this;
}

const std::string& Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::signForm(Form& f) const {
	try {
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << _name << " couldn't sign " << f.getName() 
		<< " because " << e.what() << std::endl;
	}
}

void Bureaucrat::incrementGrade() { // Creamos nuestra excepcion
	if (_grade == 1) 
	  	throw GradeTooHighException();
	else
		_grade -= 1;
}

void Bureaucrat::decrementGrade() { // Creamos otra excepcion
	 if (_grade == 150) 
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


/*----------------Insertion operator overloading------------------*/
std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj) {
	out << obj.getName() << ", bureaucrat grade " 
		<< obj.getGrade() << "." << std::endl;
	return out;
}

