#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <cstdlib>
#include <ctime>

/**
 * La clase sirve solo como contenedor funcional para el algoritmo
 *  y las utilidades asociadas. No contiene atributos, no necesito 
 * instanciar ningun objeto, por tanto sus metodos pueden ser static 
 * y sus argumentos se pasan por referencia.
 * Se llamaran directamente con PmergeMe::nombreDeFuncion().
 * La forma Canonica no sirve aqui de nada, aparece unicamente por 
 * exigencia del subject. No se permite instanciarla.
 */

class PmergeMe {
public:

	// Función de ordenamiento principal
	template <typename T>
	static void mergeInsertSort(T& container);

private:

	// Canonical Orthodox Form. No se permite instanciar
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	// Funciones auxiliares
    static std::vector<size_t> generateJacobsthalSequence(size_t n);

    template <typename T>
    static typename T::iterator binaryInsert(T& container,
                                             typename T::value_type value,
                                             typename T::iterator begin,
                                             typename T::iterator end);
};

#include "PmergeMe.tpp" // template methods

#endif
