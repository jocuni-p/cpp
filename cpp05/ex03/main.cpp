/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:46:19 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/02/23 13:46:20 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat b1("John", 1);
        Bureaucrat b2("Alice", 150);
		Bureaucrat b3;
		// Bureaucrat b4("mikel", 151);
		
        ShrubberyCreationForm f1("My_garden");
        RobotomyRequestForm f2("Spiderman");
        PresidentialPardonForm f3("Jacktheripper");
		
		std::cout << std::endl;
        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;//
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << f3 << std::endl;

        b1.signForm(f1);
        b1.signForm(f2);
        b1.signForm(f3);

        b1.executeForm(f1);
        b1.executeForm(f2);
        b1.executeForm(f3);

        b2.executeForm(f1); // This should fail due to low grade

   } catch (std::exception& e) {
       std::cerr << "Exception (in the main scope): " << e.what() << std::endl;
   }

    return 0;
}
