/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:45:42 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/02/25 15:00:40 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <cstdlib> // to manage rand()
//#include <ctime> // to manage time()
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	std::string	_target;
	
	public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& obj);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
	~RobotomyRequestForm();

	void execute(const Bureaucrat& executor) const; 
};
