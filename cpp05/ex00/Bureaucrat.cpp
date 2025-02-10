#include "Bureaucrat.hpp"

/* Constructor parametrizado */
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
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
//		_name = obj._name; // name es const y no se puede cambiar
		_grade = obj._grade;
	}
	return *this;
}

const std::string& Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

void Bureaucrat::incrementGrade() {
	 _grade -= 1;
	 if (_grade < 1)
	  		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

void Bureaucrat::decrementGrade() { 
	_grade += 1;
	 if (_grade < 1)
	  		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}


/*--------------------------out of the Bureaucratic class----------------------------*/

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj) {
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return out;
}

