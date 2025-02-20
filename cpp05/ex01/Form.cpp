#include "Form.hpp"

/*Default constructor*/
Form::Form() : _name("Default_Form"), _isSigned(false), _gradeToSign(42), _gradeToExecute(42) {}

/* Constructor parametrizado */
Form::Form(const std::string name, bool issigned, int gradetosign, int gradetoexecute) 
	: _name(name), _isSigned(issigned), _gradeToSign(gradetosign), _gradeToExecute(gradetoexecute) {
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

/* Constructor de copia */
Form::Form(const Form& obj): _name(obj._name), _isSigned(obj._isSigned), 
	_gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute) {}

Form::~Form() {}

Form& Form::operator=(const Form& obj) {
	if (this != &obj) {
	// hay variables const que no se pueden re-asignar de nuevo
		_isSigned = obj._isSigned;
	}
	return *this;
}

const std::string& Form::getName() const { return _name; }

bool Form::getIsSigned() const { return _isSigned; }

const int& Form::getGradeToSign() const { return _gradeToSign; }

const int& Form::getGradeToExecute() const { return _gradeToExecute; }

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}


/*----------------Insertion operator overloading------------------*/
std::ostream& operator<<(std::ostream& out, const Form& obj) {
	out << "Form Name: " << obj.getName() << std::endl
		<< "Is Signed: " << obj.getIsSigned() << std::endl
		<< "Grade to Sign: " << obj.getGradeToSign() << std::endl
		<< "Grade to Execute: " << obj.getGradeToExecute() << std::endl;
	return out;
}

