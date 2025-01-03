/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:29:37 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/03 18:11:24 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
	
	pr......:
		std::string	_ideas[100];

	public:
		Brain();
		~Brain();
		Brain(const Brain& other); // Copy constructor
		Brain&	operator=(const Brain& other); // Copy assignment operator overloaded
	
};

#endif
