/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:46:19 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/02/25 15:26:45 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	
    Intern intern;
	AForm* form;

    try {
        Bureaucrat Joe("Joe", 1); // Max sign power
        std::cout << Joe << std::endl;

		Bureaucrat Mila("Mila", 73); // Medium sign power
		std::cout << Mila << std::endl;

    	form = intern.makeForm("Robotomy request", "Bitwala");
		// std::cout << *form << std::endl; // To see the form values
		if (form) {
			Mila.executeForm(*form); //Should fail, because low grade
			Mila.signForm(*form); //Should fail, because low grade
			Joe.signForm(*form);
			Joe.executeForm(*form);
			delete form;
		}

		form = intern.makeForm("Shrubbery creation", "Campus");
		if (form) {
			Joe.signForm(*form);
			Joe.executeForm(*form);
			delete form;
		}

 		AForm* form2 = intern.makeForm("Presidential pardon", "Viola");
    	if (form2) {
        Joe.signForm(*form2);
        Joe.executeForm(*form2);
        delete form2;
    	}

    	form = intern.makeForm("Social insurance", "Claudia"); // Should fail, not exist
   } 
   catch (std::exception& e) {
       std::cerr << "Exception (in the main scope): " << e.what() << std::endl;
   }
    return 0;
}
