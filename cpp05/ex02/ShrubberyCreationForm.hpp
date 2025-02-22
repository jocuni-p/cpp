#pragma once
#include <iostream>
#include <string>
#include <fstream> // para manejar archivos 'file()' (lectura y escritura)
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	std::string	_target;
	
	public:
	ShrubberyCreationForm(); // Default constructor
	ShrubberyCreationForm(const std::string& target); // const parametrizado
	ShrubberyCreationForm(const ShrubberyCreationForm& obj); // const de copia
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
	~ShrubberyCreationForm(); 
	
	void execute(const Bureaucrat& executor) const; 
};
