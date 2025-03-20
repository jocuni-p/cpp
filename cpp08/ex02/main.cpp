/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:20:46 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/20 17:51:55 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <stack>
#include <iostream>
#include "MutantStack.hpp"


int main()
{
	{	
		std::list<int> myList;
		
		myList.push_back(5);
		myList.push_back(17);
		
		std::cout << myList.back() << std::endl;
		
		myList.pop_back();
		
		std::cout << myList.size() << std::endl;
		
		myList.push_back(3);
		myList.push_back(5);
		myList.push_back(737);
		myList.push_back(0);
		
		std::list<int>::iterator it = myList.begin();
		std::list<int>::iterator ite = myList.end();
		++it;
		--it;
		
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
	}
	
	{
		std::cout << "---------" << std::endl;
		MutantStack<int> mstack;

			mstack.push(5);
		mstack.push(17);
		
		std::cout << mstack.top() << std::endl;
		
		mstack.pop();
		
		std::cout << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
	}
	return 0;
}

