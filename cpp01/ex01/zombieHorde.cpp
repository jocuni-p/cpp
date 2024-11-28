/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:17:09 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/28 21:20:57 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name){

	if (N <= 0)//protector
	{
		return NULL;
	}
		
	Zombie	*z = new Zombie[N];
	
	for (int i = 0; i < N; i++)
	{
//		inicializa el atributo privado de cada Zombie
		z[i].setName(name);		
	}
//	retorna el punter al primer element del array
	return (z);
}
