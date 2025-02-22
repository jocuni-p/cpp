#pragma once
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat; //Si no lo instancio se crea una dependencia circular

class Form {
private:
	const std::string 	_name;
	bool				_isSigned;//false = NO signed
	const int			_gradeToSign;
	const int			_gradeToExecute;

public:
	Form(); // Constructor por default (forma canonica)
	Form(const std::string name, int gradetosign, int gradetoexecute); // const parametrizado
	Form(const Form& obj); // const de copia
	virtual ~Form(); // virtual asegura correcta destruccion de herencias
	Form& operator=(const Form& obj);

	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat& b);//pone isSigned en 'true' si Bureaucrat tiene grado suficiente

// Clases de excepciones
   	class GradeTooHighException : public std::exception {
   	public:
       	virtual const char* what() const throw();
   	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

//Fuera de la clase PORQUE RETORNA UN OBJETO ostream
/*======= "<<" insertion operator overload========*/
std::ostream& operator<<(std::ostream& out, const Form& obj);

