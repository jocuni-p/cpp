/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:16:17 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/10 17:23:49 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed{
	
	private:

		int					_fixp;
		static const int	_fractbits;



	public:
		Fixed();
		def conts que inits fixpoint a 0
		un copy constructor que posa valor 8 a fractbits
		un copy asignement operator overload
		~Fixed();

		int	getRawBits(void) const; //returns raw value of fixp
		void	setRawBits(int const raw); // Sets fixp raw value
	
};

#endif