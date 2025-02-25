/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:40:51 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/02/25 14:42:55 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		Bureaucrat(); 
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& obj);
		virtual ~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& obj);

		const std::string& getName() const; 
		int getGrade() const;
		void signForm(Form& f) const;
		
		void incrementGrade();
		void decrementGrade();


    	class GradeTooHighException : public std::exception {
        	public:
            	virtual const char* what() const throw();
    	};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};


std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

