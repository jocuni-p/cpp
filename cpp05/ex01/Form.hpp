#pragma once
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string 	_name;
	bool				_isSigned;//true = signed
	const int			_gradeToSign;//saltara una exception si el Burocrata no llega a este grado
	const int			_gradeToExecute;//saltara una exception si el Burocrata no llega a este grado

public:
	Form(); // Constructor por default. Lo exije la forma canonica
	Form(const std::string name, bool issigned, int gradetosign, int gradetoexecute); // const parametrizado
	Form(const Form& obj); // const de copia
	virtual ~Form(); 
	// virtual me asegura una correcta destruccion en caso de posibles herencias
	Form& operator=(const Form& obj);

	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat& b);//pone el bool a true si el Bureaucrat lo puede firmar

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

//La declaro fuera de la clase Form PORQUE RETORNA UN OBJETO DE LA CLASE ostream
/*======= "<<" insertion operator overload========*/
std::ostream& operator<<(std::ostream& out, const Form& obj);

