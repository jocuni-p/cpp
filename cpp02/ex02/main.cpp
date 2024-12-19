/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:15:41 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/19 16:57:03 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"


int	main( void ) {

	Fixed		a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "hh" << std::endl;
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
	
	Fixed		d(10);
	Fixed		e(2.5f);

	std::cout << "d = " << d << std::endl; 
	std::cout << "e = " << e << std::endl;
	std::cout << "(d < e): " << (d < e) << std::endl;
	std::cout << "(d > e): " << (d > e) << std::endl;
	std::cout << "(d >= e): " << (d >= e) << std::endl;
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
	
	Fixed		c(1);
	
	std::cout << "c = " << c << std::endl;
	std::cout << "--c = " << --c << std::endl; 
	std::cout << "c = " << c << std::endl;
	std::cout << "c++ = " << c++ << std::endl;
	std::cout << "c = " << c << std::endl;
	
	
	
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

