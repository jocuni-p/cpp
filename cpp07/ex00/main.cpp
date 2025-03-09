/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:39:15 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/08 13:28:06 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"


int main( void ) {

	int a = 2;
	int b = 3;

	std::cout << "\na = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "swap() -> " << "a = " << a << ", b = " << b << std::endl; 
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl; 
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "swap() -> " << "c = " << c << ", d = " << d << std::endl; 
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl << std::endl;

	double e = 11.11;
	double f = 77.77;

	std::cout << "e = " << e << ", f = " << f << std::endl;
	::swap(e, f);
	std::cout << "swap() -> " << "e = " << e << ", f = " << f << std::endl; 
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl; 
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl << std::endl;
	
	return 0;
}
