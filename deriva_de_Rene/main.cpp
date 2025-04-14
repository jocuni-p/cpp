#include "PmergeMe.hpp"
#include <cctype>

void sortedCheck(std::vector<int> &vec)
{
	for (size_t i = 1; i < vec.size(); ++i) {
		if (vec[i - 1] > vec[i]) {
			std::cout << "Sequence is NOT sorted!\n";
			exit(1);
		}
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
		std::string s(*input);
		for (size_t i = 0; i < s.length(); ++i) {
			if (!isdigit(s[i])) {
				std::cerr << "Error: invalid input '" << s << "'\n";
				exit(1);
			}
		}
		vec.push_back(std::atoi(*input));
		input++;
	}
	return vec;
}

void printVec(const std::vector<int> &vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
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

	std::cout << "Before: ";
	printVec(vec);

	double timeVec = PmergeMe(&vec);
	double timeDeq = PmergeMe(&deq);

	std::cout << "After: ";
	printVec(vec);

	sortedCheck(vec);

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << timeVec << " ms\n";
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque:  " << timeDeq << " ms\n";

	return 0;
}
