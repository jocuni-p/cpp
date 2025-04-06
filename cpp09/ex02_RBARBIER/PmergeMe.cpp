#include "PmergeMe.hpp"

// return the Nth element of the Jacobsthal sequence
int jacobsthal(int n)
{
	int a = 1, b = 1;
	for (int i = 0; i < n; ++i) {
		int temp = b;
		b = b + a*2;  // J(i) = J(i-1) + 2 * J(i-2)
		a = temp;
	}
	return b;  // Return J(n)
}

/*============================VECTOR============================*/
// advance the it2 iterator by 2^rec_level iteratively
bool safeIterVec(std::vector<int>::iterator *it, std::vector<int>::iterator end, int iterations)
{
	while (iterations > 0) {
		if (*it == end)
			return false;
		(*it)++;
		iterations--;
	}
	return true;
}

// binary search to find the right slot
std::list<elementVec>::iterator binarySearchVec(std::list<elementVec> &main, int elem, std::list<elementVec>::iterator boundary)
{
	std::list<elementVec>::iterator it = main.begin();
	std::list<elementVec>::iterator mid;

	while (it != boundary) {
		mid = it;
		std::advance(mid, std::distance(it, boundary) / 2);
		if (elem < mid->vec.back())
			boundary = mid;
		else {
			it = mid;
			if (std::distance(it, boundary) == 1)
				return ++it;
		}
	}
	return it;
}

// initialize the main list
void initMainVec(std::list<elementVec> *main, std::vector<int> *vec, int rec_level)
{
	elementVec elem;
	std::vector<int> sub_vec(1 << rec_level);
	std::vector<int>::iterator it = vec->begin() + (1 << rec_level);
	int tag_assign = 1;

	while (it != vec->end()) {
		std::copy(it, it + (1 << rec_level), sub_vec.begin());
		elem.vec = sub_vec;
		elem.type = 'a';
		elem.tag = tag_assign++;
		main->push_back(elem);
		if ((1 << rec_level) + (1 << (rec_level + 1)) > std::distance(it, vec->end()))
			break;
		it += 1 << (rec_level + 1);
	}
}

// initialize the pend list
elementVec initPendVec(std::list<elementVec> *pend, std::vector<int> *vec, int rec_level)
{
	elementVec elem;
	std::vector<int> sub_vec(1 << rec_level);
	std::vector<int>::iterator it = vec->begin();
	int tag_assign = 1;

	while (it != vec->end()) {
		std::copy(it, it + (1 << rec_level), sub_vec.begin());
		elem.vec = sub_vec;
		elem.type = 'b';
		elem.tag = tag_assign++;
		pend->push_back(elem);
		if ((1 << (rec_level + 2)) > std::distance(it, vec->end()))
			break;
		it += 1 << (rec_level + 1);
	}
	if ((1 << rec_level) + (1 << (rec_level + 1)) <= std::distance(it, vec->end())) {
		it += 1 << (rec_level + 1);
		std::copy(it, it + (1 << rec_level), sub_vec.begin());
		elem.vec = sub_vec;
		elem.type = 'b';
		elem.tag = tag_assign++;
		return elem;
	}
	elem.tag = 0;
	return elem;
}

// second face of the algorithm
void insertionVec(std::vector<int> *vec, int rec_level)
{
	int jacob_iteration = 1;
	std::list<elementVec> main;
	std::list<elementVec> pend;
	std::list<elementVec>::iterator tmp_it;
	elementVec odd;

	// Initialize the main and pend lists
	initMainVec(&main, vec, rec_level);
	odd = initPendVec(&pend, vec, rec_level);

	// Insert B1 into main
	main.insert(main.begin(), pend.front());
	pend.pop_front();

	while (!pend.empty()) {
		std::list<elementVec>::iterator insert = pend.begin();
		size_t insertions = jacobsthal(jacob_iteration) - jacobsthal(jacob_iteration - 1);
		if (insertions > pend.size())
			insertions = pend.size();
		std::advance(insert, insertions - 1);
		for (; insertions > 0; insertions--) {
			std::list<elementVec>::iterator boundary = main.begin();
			while (boundary->tag != insert->tag)
				boundary++;
			std::list<elementVec>::iterator slot = binarySearchVec(main, insert->vec.back(), boundary);
			main.insert(slot, *insert);
			tmp_it = insert;
			tmp_it--;
			pend.erase(insert);
			insert = tmp_it;
		}
		jacob_iteration++;
	}

	// Insert the odd elementVec
	if (odd.tag != 0) {
		std::list<elementVec>::iterator slot = binarySearchVec(main, odd.vec.back(), main.end());
		main.insert(slot, odd);
	}

	// Copy the sorted elementVecs back to one vector
	std::vector<int> new_vec;
	std::list<elementVec>::iterator it = main.begin();
	while (it != main.end()) {
		std::copy(it->vec.begin(), it->vec.end(), std::back_inserter(new_vec));
		it++;
	}
	// Copy the leftover elementVecs
	std::copy(vec->end() - (vec->size() % (1 << rec_level)), vec->end(), std::back_inserter(new_vec));
	*vec = new_vec;

	if (rec_level == 0)
		return;
	insertionVec(vec, rec_level - 1);
}

// first face of the algorithm
void pairSortRecVec(std::vector<int> *vec, unsigned int *rec_level)
{
	if (pow(2, *rec_level) > vec->size() / 2)
		return;

	std::vector<int>::iterator it = vec->begin() + pow(2, *rec_level) - 1;
	std::vector<int>::iterator it2 = vec->begin() + pow(2, *rec_level + 1) - 1;
	std::vector<int>::iterator decoy1;
	std::vector<int>::iterator decoy2;

	while (it2 != vec->end())
	{
		if (*it > *it2) {
			decoy1 = it;
			decoy2 = it2;
			while (decoy2 != it) {
				std::swap(*decoy1, *decoy2);
				decoy1--;
				decoy2--;
			}
		}
		if (!safeIterVec(&it2, vec->end(), pow(2, *rec_level + 1)))
			break;
		it += pow(2, *rec_level + 1); 
	}

	(*rec_level)++;
	pairSortRecVec(vec, rec_level);
}

// Algorithm with vector
double PmergeMeVec(std::vector<int> *vec) {
	unsigned int rec_level = 0;
	clock_t start = clock();

	pairSortRecVec(vec, &rec_level);
	insertionVec(vec, rec_level - 1);

	clock_t end = clock();
	return (static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000);
}

/*============================DEQUE============================*/
// advance the it2 iterator by 2^rec_level iteratively
bool safeIterDeq(std::deque<int>::iterator *it, std::deque<int>::iterator end, int iterations)
{
	while (iterations > 0) {
		if (*it == end)
			return false;
		(*it)++;
		iterations--;
	}
	return true;
}

// binary search to find the right slot
std::list<elementDeq>::iterator binarySearchDeq(std::list<elementDeq> &main, int elem, std::list<elementDeq>::iterator boundary)
{
	std::list<elementDeq>::iterator it = main.begin();
	std::list<elementDeq>::iterator mid;

	while (it != boundary) {
		mid = it;
		std::advance(mid, std::distance(it, boundary) / 2);
		if (elem < mid->deq.back())
			boundary = mid;
		else {
			it = mid;
			if (std::distance(it, boundary) == 1)
				return ++it;
		}
	}
	return it;
}

// initialize the main list
void initMainDeq(std::list<elementDeq> *main, std::deque<int> *deq, int rec_level)
{
	elementDeq elem;
	std::deque<int> sub_deq(1 << rec_level);
	std::deque<int>::iterator it = deq->begin() + (1 << rec_level);
	int tag_assign = 1;

	while (it != deq->end()) {
		std::copy(it, it + (1 << rec_level), sub_deq.begin());
		elem.deq = sub_deq;
		elem.type = 'a';
		elem.tag = tag_assign++;
		main->push_back(elem);
		if ((1 << rec_level) + (1 << (rec_level + 1)) > std::distance(it, deq->end()))
			break;
		it += 1 << (rec_level + 1);
	}
}

// initialize the pend list
elementDeq initPendDeq(std::list<elementDeq> *pend, std::deque<int> *deq, int rec_level)
{
	elementDeq elem;
	std::deque<int> sub_deq(1 << rec_level);
	std::deque<int>::iterator it = deq->begin();
	int tag_assign = 1;

	while (it != deq->end()) {
		std::copy(it, it + (1 << rec_level), sub_deq.begin());
		elem.deq = sub_deq;
		elem.type = 'b';
		elem.tag = tag_assign++;
		pend->push_back(elem);
		if ((1 << (rec_level + 2)) > std::distance(it, deq->end()))
			break;
		it += 1 << (rec_level + 1);
	}
	if ((1 << rec_level) + (1 << (rec_level + 1)) <= std::distance(it, deq->end())) {
		it += 1 << (rec_level + 1);
		std::copy(it, it + (1 << rec_level), sub_deq.begin());
		elem.deq = sub_deq;
		elem.type = 'b';
		elem.tag = tag_assign++;
		return elem;
	}
	elem.tag = 0;
	return elem;
}

// second face of the algorithm
void insertionDeq(std::deque<int> *deq, int rec_level)
{
	int jacob_iteration = 1;
	std::list<elementDeq> main;
	std::list<elementDeq> pend;
	std::list<elementDeq>::iterator tmp_it;
	elementDeq odd;

	// Initialize the main and pend lists
	initMainDeq(&main, deq, rec_level);
	odd = initPendDeq(&pend, deq, rec_level);

	// Insert B1 into main
	main.insert(main.begin(), pend.front());
	pend.pop_front();

	while (!pend.empty()) {
		std::list<elementDeq>::iterator insert = pend.begin();
		size_t insertions = jacobsthal(jacob_iteration) - jacobsthal(jacob_iteration - 1);
		if (insertions > pend.size())
			insertions = pend.size();
		std::advance(insert, insertions - 1);
		for (; insertions > 0; insertions--) {
			std::list<elementDeq>::iterator boundary = main.begin();
			while (boundary->tag != insert->tag)
				boundary++;
			std::list<elementDeq>::iterator slot = binarySearchDeq(main, insert->deq.back(), boundary);
			main.insert(slot, *insert);
			tmp_it = insert;
			tmp_it--;
			pend.erase(insert);
			insert = tmp_it;
		}
		jacob_iteration++;
	}

	// Insert the odd elementDeq
	if (odd.tag != 0) {
		std::list<elementDeq>::iterator slot = binarySearchDeq(main, odd.deq.back(), main.end());
		main.insert(slot, odd);
	}

	// Copy the sorted elementVecs back to one vector
	std::vector<int> new_vec;
	std::list<elementDeq>::iterator it = main.begin();
	while (it != main.end()) {
		std::copy(it->deq.begin(), it->deq.end(), std::back_inserter(new_vec));
		it++;
	}
	// Copy the leftover elementVecs
	std::copy(deq->end() - (deq->size() % (1 << rec_level)), deq->end(), std::back_inserter(new_vec));
	*deq = std::deque<int>(new_vec.begin(), new_vec.end());

	if (rec_level == 0)
		return;
	insertionDeq(deq, rec_level - 1);
}

// first face of the algorithm
void pairSortRecDeq(std::deque<int> *deq, unsigned int *rec_level)
{
	if (pow(2, *rec_level) > deq->size() / 2)
		return;

	std::deque<int>::iterator it = deq->begin() + pow(2, *rec_level) - 1;
	std::deque<int>::iterator it2 = deq->begin() + pow(2, *rec_level + 1) - 1;
	std::deque<int>::iterator decoy1;
	std::deque<int>::iterator decoy2;

	while (it2 != deq->end())
	{
		if (*it > *it2) {
			decoy1 = it;
			decoy2 = it2;
			while (decoy2 != it) {
				std::swap(*decoy1, *decoy2);
				decoy1--;
				decoy2--;
			}
		}
		if (!safeIterDeq(&it2, deq->end(), pow(2, *rec_level + 1)))
			break;
		it += pow(2, *rec_level + 1); 
	}

	(*rec_level)++;
	pairSortRecDeq(deq, rec_level);
}

// Algorithm with deque
double PmergeMeDeque(std::deque<int> *deq) {
	unsigned int rec_level = 0;
	clock_t start = clock();

	pairSortRecDeq(deq, &rec_level);
	insertionDeq(deq, rec_level - 1);

	clock_t end = clock();
	return (static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000);
}
