/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:03:52 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/14 17:58:15 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

/*====Template functions definition====*/
template <typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}


template <typename T>
const T& min(const T& a, const T& b) {
	return (a < b) ? a : b;		
}


template<typename T>
const T& max(const T& a, const T& b) {
	return (a > b) ? a : b;
}

#endif
