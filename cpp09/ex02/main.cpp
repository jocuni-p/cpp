
#include "PmergeMe.hpp"

/**
 * Verifies if all input are positive integers (0 is not accepted).
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
        long nbr = strtol(arg.c_str(), NULL, 10);
		if (nbr == 0 || nbr > INT_MAX){
			errorMsg = "Input number out of range '" + arg + "'";
			return false;
		}
	}
	return true;
}

/**
 * Check if the sequence is sorted in ascending order.
 */
template <typename Iterator>
static bool isSorted(Iterator first, Iterator last) {
	if (first == last)
		return true;
	Iterator next = first;
	next++;
	while (next != last) {
		if (*next < *first)
			return false;
		next++;
		first++;
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

	clock_t startVec = clock();
	PmergeMe::mergeInsertSort(vec);
	clock_t endVec = clock();

#ifdef PMERGEME_DEBUG
	std::cout << "/=====SECOND CONTAINER=====/\n" << std::endl;
#endif

	clock_t startDeq = clock();
	PmergeMe::mergeInsertSort(deq);
    clock_t endDeq = clock();

	std::cout << "Before: ";
	for (int i = 1; i < argc; ++i)
		std::cout << argv[i] << " ";
	std::cout << std::endl;

	std::cout << "After:  ";
    for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl
			  << std::endl;

	//Print info
	/** clock() counts CPU time in 'tick' units, not in real time. It's useful
	 * to count computing processes. To convert ticks in seconds we divide by 
	 * CLOCKS_PER_SEC. To convert seconds in ms we multiply by (double)1000.0 */
	std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : "
              << 1000.0 * (endVec - startVec) / CLOCKS_PER_SEC << " ms" << std::endl;

    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque  : "
              << 1000.0 * (endDeq - startDeq) / CLOCKS_PER_SEC << " ms" << std::endl;

	//My validation test
	std::cout << std::boolalpha; // imprime booleanos como "true" o "false" (en lugar de 1 o 0).
	std::cout << "\nIs vector sorted? " << isSorted(vec.begin(), vec.end()) << std::endl;
	std::cout << "Is deque sorted? " << isSorted(deq.begin(), deq.end()) << std::endl;

	return 0;
}

