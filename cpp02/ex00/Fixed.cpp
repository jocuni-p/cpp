/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:16:00 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/10 17:21:37 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


/*-----Default Constructor-----*/

Fixed::Fixed() {
	
	_fixp = 0;
	std::cout << "Default constructor called" << std::endl;
}






Fixed::~Fixed(){
	
	std::cout << "Destructor called" << std::endl;
}
