
#include "PmergeMe.hpp"


PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return *this; }
PmergeMe::~PmergeMe() {}

/**
 * Returns the Jacobsthal sequence, skipping the initial 0 and 1, up to 
 * the sequence number that is less than the size of the pending items to 
 * be inserted, and then appends the skipped numbers in reverse order. 
 * This return value will be used as the 1-based insertion order for adding
 * the pending items to the main list.   
 */
std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n) {
    std::vector<size_t> sequence;
    if (n == 0) return sequence;

    // Generar números puros de Jacobsthal (1, 3, 5, 11, 21...)
    sequence.push_back(1);
    if (n == 1) return sequence;

    sequence.push_back(3);
    size_t next = 5;

	//Genera los Jacobsthal puros
	while (next <= n + sequence[sequence.size()-2]) { 
        sequence.push_back(next);
        next = sequence.back() + 2 * sequence[sequence.size()-2];
    }

    // Añade los números intermedios en orden descendente
    for (size_t i = sequence.size()-1; i > 0; --i) {
        for (size_t j = sequence[i] - 1; j > sequence[i-1]; --j) {
            if (j <= n) sequence.push_back(j);
        }
    }
    return sequence;
}

