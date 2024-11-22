/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:15:14 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/21 16:52:00 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* static_cast: conversion explicita que el compilador puede verificar en 
tiempo de compilacion */

#include <iostream>
#include <cctype> // std::toupper

int main(int argc, char **argv)
{
    int i = 1;
    
    if (argc == 1) 
	{
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    } 
	else 
	{
        while (i < argc)
		{
            int j = 0;
            while (argv[i][j])
			{
                std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(argv[i][j])));
                j++;
            }
            i++;
        }
        std::cout << std::endl;
    }
    return 0;
}

