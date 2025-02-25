/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:40:59 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/02/25 14:44:50 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	Form(); 
	Form(const std::string name, int gradetosign, int gradetoexecute);
	Form(const Form& obj);
	virtual ~Form();
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

/*======= "<<" insertion operator overload========*/
std::ostream& operator<<(std::ostream& out, const Form& obj);

