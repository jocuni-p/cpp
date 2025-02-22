#pragma once
#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	std::string	_target;
	
	public:
	PresidentialPardonForm(); // Default constructor
	PresidentialPardonForm(const std::string& target); // const parametrizado
	PresidentialPardonForm(const PresidentialPardonForm& obj); // const de copia
	PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
	~PresidentialPardonForm();

	void execute(const Bureaucrat& executor) const; 
};
