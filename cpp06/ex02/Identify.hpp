/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:32:24 by jocuni-p          #+#    #+#             */
/*   Updated: 2025/03/05 14:49:49 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include <iostream>
#include "Base.hpp"
// #include "A.hpp"
// #include "B.hpp"
// #include "C.hpp"

Base* generate(void);

void identify(Base* p);

void identify(Base& p);

#endif
