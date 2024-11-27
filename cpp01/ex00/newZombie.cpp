/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:57:30 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/27 17:42:12 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie *newZombie(std::string name)
{
	Zombie	*theNewOnePtr = new Zombie(name);
//Alternativa: return(new Zombie(name));
	
	return (theNewOnePtr);
}
