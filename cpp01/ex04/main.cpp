/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:55:19 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/05 17:10:03 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

/**
 * Le paso por ref '&' los dos archivos para que sean los originales y no 
 * copias, porque entonces no se reflejaria el replace en la funcion 'main'.
 * Los s1 y s2 no importa por que son constantes y no cambiaran.
 * */
int	my_replace(std::ifstream& srcFile, std::ofstream& dstFile, std::string s1, std::string s2){

	std::string	line;
	size_t		len_s1 = s1.length();
	size_t		pos;
	
	while (std::getline(srcFile))
	

	
}



int	main(int argc, char *argv[]){
	
	std::string		filename;
	std::string		s1;
	std::string		s2;
	std::ifstream	srcFile;
	std::ofstream	dstFile;
	int			status;
	
//	Verificamos num de argumentos 	
	if (argc != 4){
		std::cout << "Usage: ./replace [filename] [string1] [string2]" << std::endl;	
		return 1;
	}
//	Convertir argumentos a string
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	
	if (s1.empty()){
		std::cerr << "Error: string to find cannot be empty" << std::endl;
		return 1;
	}
//	Abrir el archivo source
	std::ifstream srcFile(filename);
	if (!srcFile){
		std::cerr << "Error opening file '" << filename << "':" << strerror(errno) << std::endl;
		return 1;
	}

//	Crear el archivo destiny
	std::ofstream dstFile(filename + ".replace");
	if (!dstFile){
		std::cerr << "Error creating file '" << filename + ".replace" << "':" << strerror(errno) << std::endl;
		srcFile.close();
		return 1;		
	}

//Llamada a funcion que hara el replace de s1 por s2
	status = my_replace(srcFile, dstFile, s1, s2);

//Cierro los files abiertos
	srcFile.close();
	dstFile.close();

	return status;
}