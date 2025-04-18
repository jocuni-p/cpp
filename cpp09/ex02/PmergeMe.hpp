#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>	// std::lower_bound(), std::upper_bound()
#include <iterator>
#include <iostream>
#include <cstdlib>
#include <ctime>		// clock()
#include <climits>		// INT_MAX

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

	// Main sorting function
	template <typename T>
	static void mergeInsertSort(T& container);

private:

	// Canonical Orthodox Form. Not allowed to instanciate
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	// Auxiliar methods
    static std::vector<size_t> generateJacobsthalSequence(size_t n);

    template <typename T>
    static typename T::iterator binaryInsert(T& container,
                                             typename T::value_type value,
                                             typename T::iterator begin,
                                             typename T::iterator end);
};

#include "PmergeMe.tpp" // template methods implementation

#endif
