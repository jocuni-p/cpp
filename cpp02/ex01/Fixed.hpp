/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:16:17 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/16 17:04:00 by jocuni-p         ###   ########.fr       */
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

/*=======overload operator definition========*/
//	Inserta una representacion de tipo float (mediante toFloat) 
// de un fixed-point (_rawValue) en el flujo de salida (la terminal) 
// del objeto pasado como parametro.
std::ostream&  operator<<(std::ostream& out, const Fixed& fixed); // muestra el num en formato flotante usando toFloat

#endif
