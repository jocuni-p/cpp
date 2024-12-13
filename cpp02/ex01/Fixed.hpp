/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:16:17 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/13 19:57:30 by jocuni-p         ###   ########.fr       */
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
		Fixed(const int num); // Int Constructor. Convierte el argumento a un fixed-point val
		Fixed(const float num); // Float Constructor. Convierte el argumento a un fixed-point val
		Fixed(const Fixed& other); // Copy constructor
		Fixed& operator=(const Fixed& other); // Copy assignment operator overload
		~Fixed();

		int		getRawBits(void) const; //returns _rawValue
		void	setRawBits(int const raw); // Sets _rawValue
		float	toFloat(void) const; // fixed-point to float
		int		toInt(void) const; // fixed-point to int
		
};
//	Inserta una representacion de float de un fixed-point en el objeto 
// de flujo de salida pasado como parametro
//Inserta el float de un fixed en el flujo de salida de un obj
std::ostream&  operator<<(std::ostream& op, const Fixed& fixed);  //muestra el num en formato flotante usando toFloat

#endif
