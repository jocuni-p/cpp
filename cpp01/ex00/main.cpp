/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:30:05 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/27 17:39:37 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	randomChump("Betsy");
	randomChump("Jack");
	
	Zombie *thePtrZ = newZombie("Stormy");
	thePtrZ->announce();
	delete(thePtrZ);

	
	return 0;
}
