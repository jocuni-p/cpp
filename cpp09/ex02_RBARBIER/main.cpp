#include "PmergeMe.hpp"

void sortedCheck(std::vector<int> &vec)
{
	std::vector<int>::iterator it = vec.begin();
	std::vector<int>::iterator it2 = vec.begin();
	it2++;
	while (it2 != vec.end()) {
		if (*it > *it2) {
			std::cout << "Sequence is NOT sorted!\n";
			exit(1);
		}
		it++;
		it2++;
	}
	std::cout << "Sequence is sorted\n";
}

std::vector<int> getVector(char **input)
{
	std::vector<int> vec;
	if (!input || !*input) {
		std::cerr << "Error\n";
		exit(1);
	}
	while (*input) {
		if (!isdigit(**input)) {
			std::cerr << "Error\n";
			exit(1);
		}
		vec.push_back(atoi(*input));
		input++;
	}
	return vec;
}

void printVec(std::vector<int> &vec)
{
	std::vector<int>::iterator it = vec.begin();
	while (it != vec.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "Error\n";
		return 1;
	}

	std::vector<int> vec = getVector(++argv);
	std::deque<int> deq(vec.begin(), vec.end());

	// std::cout << "Before: ";
	// printVec(vec);

	// double timeVec = PmergeMeVec(&vec);
	// double timeDeq = PmergeMeDeque(&deq);

	// std::cout << "After: ";
	// printVec(vec);

	//sortedCheck(vec);
	
	double timeVec = PmergeMe(&vec);
	double timeDeq = PmergeMe(&deq);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << timeVec << " ms\n";
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque:  " << timeDeq << " ms\n";

	return 0;
}
