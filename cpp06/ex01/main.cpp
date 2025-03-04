/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:09:28 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/04 16:04:46 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main(void) {
//	Data d = {"David", 3}; // Forma alternativa de inicializar
	Data d;
	d.name = "David";
	d.grade = 4;
	Data* d1 = &d; 

	std::cout << "Data* d1:\t" << d1 << std::endl;
	std::cout << "d1->name:\t" << d1->name << std::endl;
	std::cout << "d1->grade:\t" << d1->grade << std::endl;
	
	uintptr_t d2 = Serializer::serialize(d1);
	std::cout << "serialize(d1):\t" << d2 << std::endl;
	
	Data* d3 = Serializer::deserialize(d2);
	std::cout << "deserialize(d2):" << d3 << std::endl;
	std::cout << "d3->name:\t" << d3->name << std::endl;
	std::cout << "d3->grade:\t" << d3->grade << std::endl;
	
	return 0;
}

