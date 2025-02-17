#include "Form.hpp"

/*Default constructor*/
Form::Form() : _name("Default"), _grade(42) {}

/* Constructor parametrizado */
Form::Form(const std::string name, int grade) : _name(name), _grade(grade) {
	if (_grade < 1) // Exception in out of range case!!!
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

/* Constructor de copia */
Form::Form(const Form& obj) : _name(obj._name), _grade(obj._grade) {}

Form::~Form() {}

Form& Form::operator=(const Form& obj) {
	if (this != &obj) {
	// name es const y no se puede re-asignar de nuevo
		_grade = obj._grade;
	}
	return *this;
}

const std::string& Form::getName() const { return _name; }

int Form::getGrade() const { return _grade; }


void Form::incrementGrade() {
	if (_grade == 1) // Creamos nuestra excepcion
	  	throw GradeTooHighException();
	else
		_grade -= 1;
}

void Form::decrementGrade() { 
	 if (_grade == 150) // Creamos otra excepcion
		throw GradeTooLowException();
	else
		_grade += 1;
}


const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}


/*----------------Insertion operator overloading------------------*/
std::ostream& operator<<(std::ostream& out, const Form& obj) {
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return out;
}

