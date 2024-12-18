/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:16:17 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/18 18:53:07 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP


class Fixed{
	
	private:
		int					_rawValue; // Almacena el valor en formato de punto-fijo
		static const int	_fractBits = 8; // Se inicializa aqui

	public:
	
/*=================Constructors - Canonic Form================*/

		Fixed(); // Default constructor
		~Fixed(); // Destructor
		Fixed(const Fixed& other); // Copy constructor
		Fixed&				operator=(const Fixed& other); // Copy assignment operator

/*=====================Other constructors======================*/

		Fixed(const int num); // Int Constructor. Convierte el argumento a un fixed-point val
		Fixed(const float num); // Float Constructor. Convierte el argumento a un fixed-point val

/*=======================Access methods========================*/

		int					getRawBits(void) const; //returns _rawValue
		void				setRawBits(int const raw); // Sets _rawValue
		
/*=========================Member functions====================*/
	
		float				toFloat(void) const; // fixed-point to float
		int					toInt(void) const; // fixed-point to int

/*================overload comparison operators================*/

		bool 				operator>(const Fixed& fixed) const;
		bool 				operator<(const Fixed& fixed) const;
		bool 				operator>=(const Fixed& fixed) const;
		bool 				operator<=(const Fixed& fixed) const;
		bool 				operator==(const Fixed& fixed) const;
		bool 				operator!=(const Fixed& fixed) const;

/*================overload arithmetic operators================*/

		Fixed 				operator+(const Fixed& fixed) const;
		Fixed 				operator-(const Fixed& fixed) const;
		Fixed 				operator*(const Fixed& fixed) const;
		Fixed 				operator/(const Fixed& fixed) const;

/*===========overload increment/decrement operators============*/

		Fixed&				operator++(); // post-increment
		Fixed				operator++(int); // pre-increment
		Fixed&				operator--();
		Fixed				operator--(int);

/*================overload member functions====================*/
// Retornan una referencia a un obj de clase Fixed. Es static porque 
// pertenece a la clase y no a una instancia específica de la clase y
// puede ser llamada sin necesidad de crear un objeto de tipo Fixed.
		static Fixed& 		min(Fixed& fixed1, Fixed& fixed2); // Permite que retorno y/o parametros puedan ser modificados
		static const Fixed&	min(const Fixed& fixed1, const Fixed& fixed2);// No se podra modificar ni los parametros ni la ref devuelta
		static Fixed& 		max(Fixed& fixed1, Fixed& fixed2);
		static const Fixed&	max(const Fixed& fixed1, const Fixed& fixed2);


};


/*==============overload insertion operator function===========*/
//	Muestra/inserta el valor del fixed-point de fixed en formato float 
std::ostream&  				operator<<(std::ostream& out, const Fixed& fixed);

#endif
