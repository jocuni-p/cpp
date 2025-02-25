/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:30:54 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/02/25 14:33:38 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

class Bureaucrat {
	private:
		const std::string 	_name;
		int 				_grade;

	public:
		Bureaucrat(); // Constructor por default.
		Bureaucrat(const std::string name, int grade); // const parametrizado
		Bureaucrat(const Bureaucrat& obj); // const de copia
		virtual ~Bureaucrat(); 
		// virtual asegura correcta destruccion de herencias
		Bureaucrat& operator=(const Bureaucrat& obj);

		const std::string& getName() const; 
		int getGrade() const;

		
		void incrementGrade();
		void decrementGrade();

		/*=====Clases de excepciones=====*/
    	class GradeTooHighException : public std::exception {
        	public:
            	virtual const char* what() const throw();
    	};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

//La declaro fuera de la clase Bureaucrat porque retorna un obj de otra clase (ostream)
/*======= "<<" insertion operator overload========*/
std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

