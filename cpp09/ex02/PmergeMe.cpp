#include "PmergeMe.hpp"

/*Requisitos para cumplir forma Canonica ortodoxa*/
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return *this; }
PmergeMe::~PmergeMe() {}

/**
 * Retorna la secuencia Jacobsthal, empezando por el 1 (omite el 0 y el primer 1),
 *  hasta el numero de la secuencia que sea menor que el size de pendings a insertar
 * y luego le agrega los que se han omitido en orden inverso. Por lo tanto, usaremos
 * los numeros que retorna como orden (no como indices) de insercion de los pendings
 *  a la lista principal. 
 */
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

    // Añade núms intermedios, que se salto antes, en orden descendente
    for (size_t i = sequence.size()-1; i > 0; --i) {
        for (size_t j = sequence[i-1] + 1; j < sequence[i]; ++j) {
            if (j <= n) {
                sequence.push_back(j);
            }
        }
    }

    return sequence;
}
