
#include "PmergeMe.hpp"



PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return *this; }
PmergeMe::~PmergeMe() {}

/**
 * Retorna la secuencia Jacobsthal (omite el 0 y el primer 1) hasta el numero de la 
 * secuencia que sea menor que el size de pendings a insertar y luego le agrega los 
 * que se han omitido en orden inverso. Por lo tanto, usaremos los numeros que 
 * retorna como orden 1-based (no como indices) de insercion de los pendings a la 
 * lista principal. 
 */
/*
std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n) {
    std::vector<size_t> sequence;
    if (n == 0) return sequence;

    sequence.push_back(1);
    if (n == 1) return sequence;

    sequence.push_back(3);
    size_t next = 5;
	// Genera secuencia Jacobsthal hasta un num menor o igual a pendings.size()
    while (next <= n) {
        sequence.push_back(next);
        next = sequence.back() + 2 * sequence[sequence.size()-2];
    }

    // Añade los núms intermedios, que se salto antes, en orden descendente
    for (size_t i = sequence.size()-1; i > 0; --i) {
        for (size_t j = sequence[i-1] + 1; j < sequence[i]; ++j) {
            if (j <= n) {
                sequence.push_back(j);
            }
        }
    }

    return sequence;
}
*/

/* ALTERNATIVA 1*/

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n) {
    std::vector<size_t> sequence;
    if (n == 0) return sequence;

    // Generar números puros de Jacobsthal (1, 3, 5, 11, 21...)
    sequence.push_back(1);
    if (n == 1) return sequence;

    sequence.push_back(3);
    size_t next = 5;

//    while (next <= n) {
	//Genera los Jacobsthal puros
	while (next <= n + sequence[sequence.size()-2]) {  // Asegurar que se incluya el siguiente Jacobsthal
        sequence.push_back(next);
        next = sequence.back() + 2 * sequence[sequence.size()-2];
    }

    // // Generar números intermedios en orden descendente
    // size_t last_index = sequence.size() - 1;
    // for (size_t i = last_index; i > 0; --i) {
    //     size_t current = sequence[i];
    //     size_t previous = sequence[i-1];
        
    //     // Añadir números entre previous y current (descendente)
    //     for (size_t j = current - 1; j > previous; --j) {
    //         if (j <= n) {
    //             sequence.push_back(j);
    //         }
    //     }
    // }

    // 2. Añadir números intermedios en orden descendente
    for (size_t i = sequence.size()-1; i > 0; --i) {
        for (size_t j = sequence[i] - 1; j > sequence[i-1]; --j) {  // Descendente
            if (j <= n) sequence.push_back(j);
        }
    }



    return sequence;
}

