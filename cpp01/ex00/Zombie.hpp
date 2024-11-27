/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 00:26:54 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/27 16:54:51 by jocuni-p         ###   ########.fr       */
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
	Zombie(std::string name);//el constructor sera al mismo tiempo quien le ponga nombre
	~Zombie();//no hace falta llamarlo, entrara automaticamente antes de salir de la funcion
	void	announce(void);
	
};

Zombie* newZombie(std::string name);
//				crea una clase Zombie
//				le pone nombre
//				retorna un obj Zombie
//Reservare memoria con 'new' en el 'heap' para que se pueda retornar y usar fuera del ambito de su funcion
				
void 	randomChump( std::string name );
//				crea una clase Zombie
//				le pone nombre
//				el zombie se anuncia -> llamando a 'announce'
#endif
