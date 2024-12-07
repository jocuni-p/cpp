/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:55:19 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/07 20:46:04 by jocuni-p         ###   ########.fr       */
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
int	my_replace(std::ifstream& srcFile, std::ofstream& dstFile, const std::string s1, const std::string s2) {

	std::string	line;
	size_t		len_s1 = s1.length();
	size_t		pos;
	
	while (std::getline(srcFile, line)) {
		
		pos = line.find(s1); // Finds for the pos of the first character of s1

		while (pos != std::string::npos) {//Si pos es diferente a "no encontrado", por tanto existe
			line.erase(pos, len_s1); // Borra a partir de pos en num de caracteres de s1
			line.insert(pos, s2); // Inserta a partir de pos el string s2
			pos = line.find(s1, pos + s2.length()); // Actualiza pos a despues del insertado s2
		}
		
		dstFile << line << '\n'; // Anyado la linea acabada y terminada con \n al archivo de destino/salida
	}
	
	return 0;	
}



int	main(int argc, char *argv[]){
	
	std::string		filename;
	std::string		s1;
	std::string		s2;
	int				status;
	
//	Verificamos num de argumentos 	
	if (argc != 4){
		std::cout << "Usage: ./replace [filename] [string to replace] [new string]" << std::endl;	
		return 1;
	}
//	Convertir argumentos a string
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	
	if (s1.empty()){ // if the string is empty return true
		std::cerr << "Error: string to find cannot be empty" << std::endl;
		return 1;
	}
//	Abrir el archivo source
	std::ifstream srcFile(filename.c_str()); // Aqui declaro e inicializo la variable para su constructor.
//	He de usar c_str para convertir filename a tipo char * porque en C++98 no acepta un std:string
	if (!srcFile){
		std::cerr << "Error opening file '" << filename << "':" << strerror(errno) << std::endl;
		return 1;
	}
	std::cout << "***Input '" << filename << "' opened correctly.***" << std::endl;
	
//	Crear el archivo destiny
	std::ofstream dstFile((filename + ".replace").c_str()); // Aqui declaro e inicializo la variable para su constructor
	if (!dstFile){
		std::cerr << "Error creating file '" << filename + ".replace" << "':" << strerror(errno) << std::endl;
		srcFile.close();
		return 1;		
	}
	std::cout << "***Output '" << filename + ".replace"<< "' created correctly.***" << std::endl;
	
//Llamada a funcion que hara el replace de s1 por s2
	status = my_replace(srcFile, dstFile, s1, s2);

//Cierro los files abiertos
	srcFile.close();
	dstFile.close();

	std::cout << "***Replacement complete. Output saved to '" << filename + ".replace" << "'***" << std::endl;


	return status;
}
