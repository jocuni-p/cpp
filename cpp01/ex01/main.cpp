/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:22:42 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/28 22:35:24 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){	
	
	int	N = 3;
	
//	llamada a zombieHorde
	Zombie *hordeZombie = zombieHorde(N, "hordeZombieMember");
	if (!hordeZombie)
	{
		std::cout << "Memory allocation failure" << std::endl;
		return 1;
	}
	
	for (int i = 0; i < N; i++)
	{
		hordeZombie[i].announce();
	}
	delete[] hordeZombie;
	return 0;
}
