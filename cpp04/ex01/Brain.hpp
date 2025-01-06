/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:29:37 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/01/04 20:01:31 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
	
	private:
		std::string	_ideas[100];

	public:
		Brain();
		~Brain();
		Brain(const Brain& other); // Copy constructor
		Brain&	operator=(const Brain& other); // Copy assignment operator overloaded
	
};

#endif
