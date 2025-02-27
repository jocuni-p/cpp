/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:39:20 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/02/25 14:39:21 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"


int main() {
    try {

		Bureaucrat a; // Creara un Bureaucrat 'Default'
		std::cout << a << std::endl; // El operador '<<' actuara segun defina mi sobrecarga

        Bureaucrat b("Alice", 149);
        std::cout << b << std::endl;

        b.decrementGrade(); 
        std::cout << b << std::endl;

		Bureaucrat bCopy(b); // Provando el constructor de copia
		std::cout << "Copied Bureaucrat: " << bCopy <<std::endl;

		bCopy.decrementGrade(); // Should launch an exception 
//    	std::cout << b << std::endl;

//		Bureaucrat c("Maggy", -9);
//        std::cout << c << std::endl;

        // Intento de crear un burócrata con grade inválido
//        Bureaucrat b2("Bob", 151);  // Esto lanzará GradeTooLowException
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
