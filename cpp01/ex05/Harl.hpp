/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:35:39 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/10 15:43:31 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
private:

	void	_debug(void);
	void	_info(void);
	void	_warning(void);
	void	_error(void);

public:

	Harl();
	~Harl();
	
	void	complain(std::string level);	
};

#endif
