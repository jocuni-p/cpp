/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:46:38 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/02/25 15:12:53 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat; //Si no lo instancio se crea una dependencia circular

class AForm {
private:
	const std::string 	_name;
	bool				_isSigned;//false = NO signed
	const int			_gradeToSign;
	const int			_gradeToExecute;

	AForm(); // Def Constructor, no se podra usar. No se implementará.

public:
	AForm(const std::string name, int gradetosign, int gradetoexecute); // const parametrizado
	AForm(const AForm& obj); // const de copia
	AForm& operator=(const AForm& obj);
	virtual ~AForm(); // virtual asegura correcta destruccion de herencias

	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat& b);
	virtual void execute(const Bureaucrat& executor) const = 0;//sera implementada por las clases derivadas 

	// Exception classes inside AForm
   	class GradeTooHighException : public std::exception {
   	public:
       	virtual const char* what() const throw();
   	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

//Fuera de la clase PORQUE RETORNA UN OBJETO ostream
/*======= "<<" insertion operator overload========*/
std::ostream& operator<<(std::ostream& out, const AForm& obj);

