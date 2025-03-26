/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:55:34 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/26 16:57:35 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <exception>
#include <iomanip> // setprecision(), fixed()
#include <algorithm> // count()

class BitcoinExchange {
	private:
		std::map<std::string, float> _BtcExchange;
	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange &operator=(const BitcoinExchange& obj);
		~BitcoinExchange();

		void loadData(const std::string& filename);
		void processInput(const std::string& filename);
		float getRate(const std::string& date);
		bool isDateValid(const std::string& date);
		void printRate(const std::string& date);
};

#endif