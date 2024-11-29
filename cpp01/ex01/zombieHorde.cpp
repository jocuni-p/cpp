/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:17:09 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/29 13:08:47 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name){

//	if (N <= 0)//protector.
//	{
//		return NULL;
//	}
		
	Zombie	*z = new Zombie[N];
	
	for (int i = 0; i < N; i++)
	{
//		inicializa el atributo privado de cada Zombie
		z[i].setName(name);		
	}
//	retorna el puntero al primer elemento del array
	return (z);//Al haberse creado en el heap la puedo retornar
}
