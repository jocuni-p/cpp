#pragma once
#include <iostream>
#include <exception>
#include <lalibreria de booleans>

class Form {
private:
	const std::string 	_name;
	bool				_isSigned;
	const int			_gradeToSign;//saltara una exception si no llega
	const int			_gradeToExecute;//saltara una exception si no llega

public:
	Form(); // Constructor por default. Lo exije la forma canonica
	Form(const std::string name, int grade); // const parametrizado
	Form(const Form& obj); // const de copia
	virtual ~Form(); 
	// virtual me asegura una correcta destruccion en caso de posibles herencias
	Form& operator=(const Form& obj);

	const std::string& getName() const;
	bool getIsSigned() const;
	const int& getGradeToSign() const; // OJO ha de llevar & el retorno ???
	const int& getGradeExecute() const; // OJO ha de llevar & el retorno ???

	void beSigned(const Bureaucrat& name);//pone el bool como true si el grade del Bureaucrat es igual o superior al requerido

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

