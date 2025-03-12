/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:16:06 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/12 17:10:49 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFINFD_HPP

#include <algorithm>


//BUSCAR UN INT DENTRO DE UN CONTAINER
//La funcion retornara una referencia a un iterador de tipo T
/*La funcion debera ser compatible con cualquier container que soporte iteradores
y el algoritmo std::find.
El contenedor sera compatible con std::find()) si tiene los métodos .begin() y
 .end() y permite recorrer sus elementos de manera secuencial.*/

template <typename T>  // T es un container de int
T& it easyfind(T& container, int nbr) {
	buscar nbr en 'T' // revisar los diferentes tipos de containers
		T&::iterator it = T&.find(nbr);
	if (it == T&.end())
		throw exception o un error value return T & it;
	return it;
}


definir la exception
#endif
