#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm; //declaración adelantada, para romper la dependencia circular entre Bureaucrat.hpp y Form.hpp.

class Bureaucrat {
	private:
		const std::string 	_name;
		int 				_grade;

	public:
		Bureaucrat(); // Constructor por default (forma canonica)
		Bureaucrat(const std::string name, int grade); // const parametrizado
		Bureaucrat(const Bureaucrat& obj); // const de copia
		Bureaucrat& operator=(const Bureaucrat& obj);
		virtual ~Bureaucrat(); // virtual asegura correcta destruccion de herencias

		const std::string& getName() const; 
		int getGrade() const;
		
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm& form) const;
		void executeForm(const AForm& form);

	// Clases de excepciones
    	class GradeTooHighException : public std::exception {
        	public:
            	virtual const char* what() const throw();
    	};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		// class NotGradeToExecuteException : public std::exception {
		// 	public:
		// 		virtual const char* what() const throw();
		// };
};

//Fuera de la clase PORQUE RETORNA UN OBJETO ostream
/*======= "<<" insertion operator overload========*/
std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

