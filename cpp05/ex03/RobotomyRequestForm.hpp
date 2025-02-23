/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:45:42 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/02/23 13:45:44 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <cstdlib> // para funcion random rand()
#include <ctime> // para time()
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	std::string	_target;
	
	public:
	RobotomyRequestForm(); // Default constructor
	RobotomyRequestForm(const std::string& target); // const parametrizado
	RobotomyRequestForm(const RobotomyRequestForm& obj); // const de copia
	RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
	~RobotomyRequestForm();

	void execute(const Bureaucrat& executor) const; 
};
