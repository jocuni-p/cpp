#include "PmergeMe.hpp"

/**
 * Verifies if all input are positive integers.
 * Duplicates are accepted.*/
static bool isInputValid(int argc, char **argv, std::string& errorMsg){
	if (argc < 3) {
		errorMsg = "Usage: ./PmergeMe <at_least_2_positive_integers...>";
		return false;
	}

	for (int i = 1; i < argc; ++i){
		std::string arg = argv[i];
		for (size_t j = 0; j < arg.size(); ++j){
			if (!isdigit(arg[j])){
				errorMsg = "Invalid charcter in input '" + arg + "'";
				return false;
			}
		}
        long nbr = strtol(arg.c_str(), nullptr, 10);
		if (nbr == 0 || nbr > INT_MAX){
			errorMsg = "Input number out of range '" + arg + "'";
			return false;
		}
	}
	return true;
}


int main(int argc, char** argv)
{
	std::string errorMsg;
	if (!isInputValid(argc, argv, errorMsg)) {
		std::cerr << "Error: " << errorMsg << std::endl;
		return 1;
	}

	std::vector<unsigned int> vec;
	std::deque<unsigned int> deq;

	for (int i = 1; i < argc; ++i) {
        int value = std::atoi(argv[i]);//uso atoi porque he validado que los argv son correctos
        vec.push_back(value);
        deq.push_back(value);
	}

	std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    clock_t startVec = clock();
	PmergeMe::mergeInsertSort(vec);
	clock_t endVec = clock();

	std::cout << "\n-----------------" << std::endl;

	clock_t startDeq = clock();
	PmergeMe::mergeInsertSort(deq);
    clock_t endDeq = clock();
	
    std::cout << "After:  ";
    for (size_t i = 0; i < vec.size(); ++i)
	std::cout << vec[i] << " ";
	std::cout << std::endl
			  << std::endl;

	std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : "
              << 1000.0 * (endVec - startVec) / CLOCKS_PER_SEC << " ms" << std::endl;

    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque  : "
              << 1000.0 * (endDeq - startDeq) / CLOCKS_PER_SEC << " ms" << std::endl;

	//Result validation
	std::cout << std::boolalpha; // imprime booleanos como "true" o "false" (en lugar de 1 o 0).
	std::cout << "\nIs vector sorted? " << std::is_sorted(vec.begin(), vec.end()) << std::endl;
	std::cout << "Is deque sorted? " << std::is_sorted(deq.begin(), deq.end()) << std::endl;

	return 0;
}

/*
#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <algorithm> // std::sort
#include <iostream>
#include <cstdlib>   // std::rand, std::srand
#include <ctime>     // std::time

int main() {
    std::srand(std::time(0));

    // Crear un vector aleatorio
    std::vector<int> original;
    for (int i = 0; i < 21; ++i)
        original.push_back(std::rand() % 1000); // números entre 0 y 999
		//Print
		std::cout << "Original: ";
		for (size_t i = 0; i < original.size(); ++i)
			std::cout << original[i] << " ";
		std::cout << "\n";


    // Copiar a std::vector y std::deque
    std::vector<int> vec = original;
    std::deque<int> deq(original.begin(), original.end());

    // Ordenar usando PmergeMe
    PmergeMe::mergeInsertSort(vec);
    PmergeMe::mergeInsertSort(deq);

    // Ordenar con std::sort para comparar
    std::vector<int> expected = original;
    std::sort(expected.begin(), expected.end());

	std::cout << "\n================================\n" << std::endl;

	// Mostrar resultados
    std::cout << "Sorted with mergeInsertSort (vector): ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << "\n";

    std::cout << "Sorted with std::sort (expected):     ";
    for (size_t i = 0; i < expected.size(); ++i)
        std::cout << expected[i] << " ";
    std::cout << "\n";

    if (vec == expected)
        std::cout << "\n[✔] std::vector está correctamente ordenado.\n";
    else
        std::cout << "[✘] Error en la ordenación con std::vector.\n";

    if (std::vector<int>(deq.begin(), deq.end()) == expected)
        std::cout << "[✔] std::deque está correctamente ordenado.\n";
    else
        std::cout << "[✘] Error en la ordenación con std::deque.\n";

    return 0;
}
*/

