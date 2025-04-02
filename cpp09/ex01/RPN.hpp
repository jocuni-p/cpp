/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 12:40:57 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/30 22:35:38 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

class RPN {
private:
	std::stack<int> _stackRPN;

	RPN(const RPN& copy);
	RPN& operator=(const RPN& obj);
	
public:
	RPN();
	~RPN();

	int calculation(const std::string& input);
};

#endif
