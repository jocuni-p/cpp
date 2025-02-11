#include "Bureaucrat.hpp"

/*Default constructor*/
Bureaucrat::Bureaucrat() : _name("Default"), _grade(42) {}

/* Constructor parametrizado */
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	if (_grade < 1) //OJO->no se deberia poder instanciar si el parametro _grade esta fuera de rango !!!
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

/* Constructor de copia */
Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name), _grade(obj._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
	if (this != &obj) {
	// name es const y no se puede asignar de nuevo
		_grade = obj._grade;
	}
	return *this;
}

const std::string& Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }


void Bureaucrat::incrementGrade() {
	if (_grade == 1) //No podra ser menor porque el constructor no permite el fuera de rango
	  	throw GradeTooHighException();
	else
		_grade -= 1;
}

void Bureaucrat::decrementGrade() { 
	 if (_grade == 150) //No podra ser menor porque el constructor lo topara
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



/*--------------------------out of the Bureaucratic class----------------------------*/

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj) {
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return out;
}

