#include "PresidentialPardonForm.hpp"

/*Default constructor*/
PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("Presidential pardon", 25, 5), _target("Default_target") {
}

/* Constructor parametrizado */
//llama al const parametrizado de su clase base con los parametros fijos 
//y inicializa target
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
	: AForm("Presidential pardon", 25, 5), _target(target) { 
}

/* Constructor de copia */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) 
	: AForm(obj), _target(obj._target) {}

/* Operador de asignacion de copia*/	
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
	if (this != &obj) {
		AForm::operator=(obj);
		_target = obj._target; 
	}
	return *this;
}

/*Destroyer*/
PresidentialPardonForm::~PresidentialPardonForm() {}


void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw NotGradeToExecuteException();
	std::cout << "\"" << _target << "\" has been pardoned by Zaphod Beeblebrox." 
	<< std::endl;
}
