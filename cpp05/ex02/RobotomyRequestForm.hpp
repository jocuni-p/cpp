#pragma once
#include <iostream>
#include <string>
#include <cstdlib> // para rand()
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	std::string	_target;
	
	public:
	RobotomyRequestForm(); // Default constructor
	RobotomyRequestForm(const std::string& target); // const parametrizado
	RobotomyRequestForm(const RobotomyRequestForm& obj); // const de copia
	RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
	~RobotomyRequestForm();

	void execute(const Bureaucrat& executor) const; 
};
