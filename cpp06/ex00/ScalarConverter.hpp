/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:58:02 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/02/26 18:58:46 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>



class ScalarConverter {
private:

	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	ScalarConverter& operator=(const ScalarConverter& obj);
	
	
public:

	~ScalarConverter(); // No estic segur si es privat ????
	static void convert(std::string input);
};

//Aqui declarare totes les funcions auxiliars de 'convert'