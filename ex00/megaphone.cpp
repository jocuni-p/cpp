/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:15:14 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/12 17:23:21 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int	i;
	int	cnt = 1;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (argv && argv[cnt])
		{
			i = 0;
			while (argv[cnt][i])
			{
				argv[cnt][i] = toupper(argv[cnt][i]);
				i++;
			}
			std::cout << argv[cnt];
			cnt++;
		}
	std::cout << std::endl;
	}
	return (0);
}
