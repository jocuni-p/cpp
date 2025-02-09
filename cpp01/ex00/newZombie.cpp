/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:57:30 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/28 18:18:18 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie *newZombie(std::string name)
{
	if (name.empty())//return true is the string is empty, otherwise returns 0
		name = "unknown";
	Zombie	*theNewOnePtr = new Zombie(name);
	
	return (theNewOnePtr);
//	Alternativa: return(new Zombie(name));
}
