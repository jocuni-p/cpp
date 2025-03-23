/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:55:34 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/23 20:33:32 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>


class BitcoinExchange {
	private:
		std::map<std::string, double> _BtcExchange;
	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange &operator=(const BitcoinExchange& obj);
		~BitcoinExchange();

		void loadCSV(const std::string& filename);
		void processInput(const std::string& filename);
		float getRate(const std::string& date);
		bool isDateValid(const std::string& date);
};

#endif