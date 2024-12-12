/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:16:17 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/12 16:05:40 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP


class Fixed{
	
	private:
		int					_rawValue;
		static const int	_fractBits = 8; // No se inicializara en el .cpp

	public:
		Fixed(); // Default constructor
		Fixed(const Fixed& other); // Copy constructor
		Fixed& operator=(const Fixed& other); // Copy assignment operator overload

		Fixed(const int num); // Constructor. Convierte el argumento a un fixed-point val
		Fixed(const float num); // Constructor. Convierte el argumento a un fixed-point val

		~Fixed();

		int		getRawBits(void) const; //returns _rawValue
		void	setRawBits(int const raw); // Sets _rawValue raw value

		float	toFloat(void) const; // Converts a fixed-point to a floating-point val
		int		toInt(void) const; // Converts a fixed-point to integer	
};

std::??????

#endif
