/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:16:37 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/20 17:55:02 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
//#include <iterator>

int main() {

	std::vector<int> vector;
	std::list<int> list;
	std::deque<int> deque;

	for (int i = 0; i < 10; i++)
	{
		vector.push_back(i);
		list.push_back(i);
		deque.push_back(i);
	}


	/* ===TEST VECTOR CONTAINER === */	
	try {
		std::cout << "\nvector<int>: ";
		printContainer(vector);
		std::vector<int>::iterator it = easyfind(vector, 4); //includes a throw
		std::cout << "Found: " << *it << std::endl;
//		std::cout << "Test easyfind(vector, nbr): OK\n" << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << "easyfind(vector, nbr): FAIL" << std::endl;
		std::cerr << e.what() << std::endl;
	}
	std::cout << "------------------------" << std::endl;

	/* ===TEST LIST CONTAINER === */
	try
	{
		std::cout << "list<int>: ";
		printContainer(list);
		std::list<int>::iterator it = easyfind(list, 5); //includes a throw
		std::cout << "Found: " << *it << std::endl;
		//		std::cout << "easyfind(list, nbr): OK\n" << std::endl;
	}
	catch(std::exception& e) {
		std::cout << "easyfind(list, nbr): FAIL" << std::endl;
		std::cerr << e.what() << std::endl;
	}
	std::cout << "------------------------" << std::endl;
	/* ===TEST DEQUE CONTAINER === */
	try {
		std::cout << "deque<int>: ";
		printContainer(deque);
		std::deque<int>::iterator it = easyfind(deque, 1); 
//		std::cout << "Test easyfind(deque, nbr): OK\n" << std::endl;
		std::cout << "Found: " << *it << std::endl;
		}
	catch(std::exception& e) {
		std::cout << "easyfind(deque, nbr): FAIL" << std::endl;
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	return 0;
}
