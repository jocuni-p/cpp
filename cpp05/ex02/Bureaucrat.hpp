/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:46:25 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/02/25 14:58:09 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		Bureaucrat(); 
		Bureaucrat(const std::string name, int grade); 
		Bureaucrat(const Bureaucrat& obj); 
		Bureaucrat& operator=(const Bureaucrat& obj);
		virtual ~Bureaucrat();

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
};


/*======= "<<" insertion operator overload========*/
std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);
