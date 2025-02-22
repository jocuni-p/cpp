#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form; //declaración adelantada, para romper la dependencia circular entre Bureaucrat.hpp y Form.hpp.

class Bureaucrat {
	private:
		const std::string 	_name;
		int 				_grade;

	public:
		Bureaucrat(); // Constructor por default (forma canonica)
		Bureaucrat(const std::string name, int grade); // const parametrizado
		Bureaucrat(const Bureaucrat& obj); // const de copia
		virtual ~Bureaucrat(); // virtual asegura correcta destruccion de herencias
		Bureaucrat& operator=(const Bureaucrat& obj);

		const std::string& getName() const; 
		int getGrade() const;
		void signForm(Form& f) const;
		
		void incrementGrade();
		void decrementGrade();

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
std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

