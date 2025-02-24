/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:29:15 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/02/24 17:19:45 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
	
		Intern(); // Default constructor
		Intern(const Intern& copy); // copy constructor
		Intern& operator=(const Intern& obj); // Asignation operator
		~Intern(); // Destroyer
		
		AForm* makeForm(const std::string& formName, const std::string& target);	
};