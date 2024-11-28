/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:24:10 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/28 22:28:56 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
private:
	std::string	_name;
	
public:
	Zombie(); 
	~Zombie();//entrara automaticamente antes de salir de la funcion o al invocar a 'delete'
	
	void	announce(void);
	void	setName(std::string name);
};


Zombie*	zombieHorde( int N, std::string name );


#endif

