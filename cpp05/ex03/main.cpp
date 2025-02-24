/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:46:19 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/02/24 23:10:12 by jocuni-p         ###   ########.fr       */
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

    form = intern.makeForm("Robotomy request", "Bender");
    if (form) {
        std::cout << "Formulario creado con éxito: " << form->getName() << std::endl;
        delete form;
    }

    form = intern.makeForm("invalid form", "Nobody"); // Debería fallar
    if (!form) {
        std::cout << "No se creó ningún formulario." << std::endl;
    }

    return 0;
}
