/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:44:45 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/29 17:30:39 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void){
	
	std::string		str = "HI THIS IS BRAIN";
	
	std::string		*stringPTR = &str;
	
	std::string& 	stringREF = str;//SIEMPRE se ha de inicializar en la declaracion
	
	
	std::cout << std::endl;
	std::cout << "string str        = \"HI THIS IS BRAIN\";" << std::endl;
	std::cout << "string *stringPTR = &str;" << std::endl;
	std::cout << "string& stringREF = str;" << std::endl;
	std::cout << std::endl;	
	std::cout << "ADDRESS of the string variable: " << &str << std::endl;
	std::cout << "ADDRESS held by stringPTR:      " << stringPTR << std::endl;
	std::cout << "ADDRESS held by stringREF:      " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "VALUE of the string variable:   " << str << std::endl;
	std::cout << "VALUE pointed to by stringPTR:  " << *stringPTR << std::endl;
	std::cout << "VALUE pointed to by stringREF:  " << stringREF << std::endl;
	std::cout << std::endl;	
	return 0;
}
