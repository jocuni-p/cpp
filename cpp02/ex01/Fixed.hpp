/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:16:17 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/23 11:23:45 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP


class Fixed{
	
	private:
		int					_rawValue; // Almacena el valor en formato de punto-fijo
		static const int	_fractBits = 8; // Se inicializa aqui

	public:
		Fixed(); // Default constructor
		Fixed(const int num); // Int Constructor. Convierte el argumento a un fixed-point val
		Fixed(const float num); // Float Constructor. Convierte el argumento a un fixed-point val
		Fixed(const Fixed& other); // Copy constructor
		~Fixed();

		Fixed& operator=(const Fixed& other); // Copy assignment operator overload

		int		getRawBits(void) const; //returns _rawValue
		void	setRawBits(int const raw); // Sets _rawValue
		float	toFloat(void) const; // fixed-point to float
		int		toInt(void) const; // fixed-point to int
		
};

/*=======overload "<<" operator definition========*/
//	Inserta en el flujo de salida (ostream) el float (mediante toFloat) 
// del _rawValue (fixed-point) del objeto pasado como parametro.
std::ostream&  operator<<(std::ostream& out, const Fixed& fixed);

#endif
