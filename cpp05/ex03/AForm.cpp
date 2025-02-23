/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:46:45 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/02/23 13:46:46 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


/* Constructor parametrizado */
AForm::AForm(const std::string name, int gradetosign, int gradetoexecute) 
	: _name(name), _isSigned(false), _gradeToSign(gradetosign), _gradeToExecute(gradetoexecute) {
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

/* Constructor de copia */
AForm::AForm(const AForm& obj): _name(obj._name), _isSigned(obj._isSigned), 
_gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute) {}


AForm& AForm::operator=(const AForm& obj) {
	if (this != &obj) {
		// Los atributos 'const' NO se pueden re-asignar
		_isSigned = obj._isSigned;
	}
	return *this;
}

AForm::~AForm() {}


const std::string& AForm::getName() const { return _name; }

bool AForm::getIsSigned() const { return _isSigned; }

int AForm::getGradeToSign() const { return _gradeToSign; }

int AForm::getGradeToExecute() const { return _gradeToExecute; }

void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}



const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form can't be executed because it is not signed!"; 
}


/*----------------Insertion operator overloading------------------*/
std::ostream& operator<<(std::ostream& out, const AForm& obj) {
	out << "AForm name: " << obj.getName()
		<< "\nSigned: " << (obj.getIsSigned() ? "Yes" : "No")
		<< "\nGrade to Sign: " << obj.getGradeToSign()
		<< "\nGrade to Execute: " << obj.getGradeToExecute() 
		<< std::endl;
	return out;
}

