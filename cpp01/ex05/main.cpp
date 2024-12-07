/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:34:43 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/07 20:01:41 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int	main(int argc, char *argv[])
{
	Harl	harl;

	if (argc == 2)
		harl.complain(argv[1]);

	else
	{
		std::cerr << "Usage: ./harl <complain level>" << std::endl;
		std::cerr << "Accepted complain levels: 'debug', 'info', 'warning', 'error'" << std::endl;
		return 1;
	}

	return 0;
}

/**
 * Alternative main
 */
/*
int	main()
{
	Harl harl;

	harl.complain("debug");
	harl.complain("info");
	harl.complain("warning");
	harl.complain("error");
	
	harl.complain("hahaha");
	return 0;
}
*/


