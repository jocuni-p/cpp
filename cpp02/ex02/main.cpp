/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:15:41 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/20 16:45:29 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"


int	main( void ) {

	Fixed		a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	Fixed		d(10);
	Fixed		e(2.5f);
	Fixed		c(1);
	Fixed  		f(50);
	Fixed  		g(100);
	
	std::cout << "============" << std::endl;
	std::cout << "SUBJECT TEST" << std::endl;
	std::cout << "============" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl; // Pre-increment. Increments and show the incremented value.
	std::cout << a << std::endl;
	std::cout << a++ << std::endl; // Post-increment. Shows the current value and then increments it.
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	std::cout << "============" << std::endl;
	std::cout << "MY OWN TESTS" << std::endl;
	std::cout << "============" << std::endl;
	std::cout << " COMPARISON   " << std::endl;
	std::cout << "============" << std::endl;
	std::cout << "d = " << d << std::endl; 
	std::cout << "e = " << e << std::endl;
	std::cout << "(d < e): " << (d < e) << std::endl;
	std::cout << "(d > e): " << (d > e) << std::endl;
	std::cout << "(d >= e): " << (d >= e) << std::endl;
	std::cout << "(d <= e): " << (d <= e) << std::endl;
	std::cout << "(d == e): " << (d == e) << std::endl;
	std::cout << "(d != e): " << (d != e) << std::endl;

	std::cout << "============" << std::endl;
	std::cout << " ARITHMETIC   " << std::endl;
	std::cout << "============" << std::endl;
	std::cout << "d = " << d << std::endl; 
	std::cout << "e = " << e << std::endl;
	std::cout << "(d + e): " << (d + e) << std::endl;
	std::cout << "(d - e): " << (d - e) << std::endl;
	std::cout << "(d * e): " << (d * e) << std::endl;
	std::cout << "(d / e): " << (d / e) << std::endl;

	std::cout << "============" << std::endl;
	std::cout << "    ++/--    " << std::endl;
	std::cout << "============" << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "--c = " << --c << std::endl; 
	std::cout << "c = " << c << std::endl;
	std::cout << "c++ = " << c++ << std::endl;
	std::cout << "c = " << c << std::endl;
	
	std::cout << "==================" << std::endl;
	std::cout << "FUNCTIONS OVERLOAD   " << std::endl;
	std::cout << "==================" << std::endl;
	std::cout << "f = " << f << std::endl;
	std::cout << "g = " << g << std::endl;
	std::cout << "max (f, g): " << Fixed::max(f , g) << std::endl;
	std::cout << "const max (const f, const g): " << (Fixed const) Fixed::max((Fixed const)f, (Fixed const)g) << std::endl;
	std::cout << "min (f, g): " << Fixed::min(f , g) << std::endl;
	std::cout << "const min (const f, const g): " << Fixed::min(f, g) << std::endl;

	return 0;
} 

/* ---------expected output----------
$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>
*/

