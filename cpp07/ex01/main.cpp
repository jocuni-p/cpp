/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:25:18 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/08 20:40:37 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"


int main(void) {
	
	int arr_int[] = {10, 20, 30, 40, 50};
	size_t len = sizeof(arr_int) / sizeof(arr_int[0]); // lo puedo hacer asi porque es un array estatico
	iter(arr_int, len, printElem<int>); //especifico el tipo porque es funcion plantilla
	std::cout << "\n=========\n" << std::endl;
	
	std::string arr_str[] = {"word1", "word2", "word3"};
	len = sizeof(arr_str) / sizeof(arr_str[0]);
	iter(arr_str, len, printElem<std::string>);
	std::cout << "\n=========\n" << std::endl;

	float arr_flo[] = {10.3f, 20.3f, 30.3f, 40.3f};
	len = sizeof(arr_flo) / sizeof(arr_flo[0]);
	iter(arr_flo, len, addOne<float>);
	for (size_t i = 0; i < len; i++)
		printElem(arr_flo[i]);
	std::cout << "\n=========\n" << std::endl;

	return 0;
}
