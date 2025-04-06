#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <cmath>
#include <list>
#include <string>

double PmergeMeVec(std::vector<int> *vec);
double PmergeMeDeque(std::deque<int> *deq);
int jacobsthal(int n);

struct elementVec {
	char type;
	int tag;
	std::vector<int> vec;
};

struct elementDeq {
	char type;
	int tag;
	std::deque<int> deq;
};

template <typename T> 
struct element {
	char type;
	int tag;
	T content;
};

template <typename T>
bool safeIter(typename T::iterator *it, typename T::iterator end, int iterations)
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
template <typename T>
typename T::iterator binarySearch(typename std::list<element<T> > &main, int elem, typename std::list<element<T> >::iterator boundary)
{
	typename std::list<element<T> >::iterator it = main.begin();
	typename std::list<element<T> >::iterator mid;

	while (it != boundary) {
		mid = it;
		std::advance(mid, std::distance(it, boundary) / 2);
		if (elem < mid->content.back())
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
template <typename T, template <typename> class Container>
void initMain(std::list<element<T> > *main, T *vec, int rec_level)
{
    element<T> elem;
    Container<int> sub_cont(1 << rec_level);  // Use template for the container type
    typename T::iterator it = vec->begin() + (1 << rec_level);
    int tag_assign = 1;

    while (it != vec->end()) {
        std::copy(it, it + (1 << rec_level), sub_cont.begin());
        elem.content = sub_cont;
        elem.type = 'a';
        elem.tag = tag_assign++;
        main->push_back(elem);
        if ((1 << rec_level) + (1 << (rec_level + 1)) > std::distance(it, vec->end()))
            break;
        it += 1 << (rec_level + 1);
    }
}

// initialize the pend list
template <typename T, template <typename> class Container>
element<T> initPend(std::list<element<T> > *pend, T *vec, int rec_level)
{
	element<T> elem;
	Container<int> sub_cont(1 << rec_level);
	typename T::iterator it = vec->begin();
	int tag_assign = 1;

	while (it != vec->end()) {
		std::copy(it, it + (1 << rec_level), sub_cont.begin());
		elem.content = sub_cont;
		elem.type = 'b';
		elem.tag = tag_assign++;
		pend->push_back(elem);
		if ((1 << (rec_level + 2)) > std::distance(it, vec->end()))
			break;
		it += 1 << (rec_level + 1);
	}
	if ((1 << rec_level) + (1 << (rec_level + 1)) <= std::distance(it, vec->end())) {
		it += 1 << (rec_level + 1);
		std::copy(it, it + (1 << rec_level), sub_cont.begin());
		elem.content = sub_cont;
		elem.type = 'b';
		elem.tag = tag_assign++;
		return elem;
	}
	elem.tag = 0;
	return elem;
}

// second face of the algorithm
template <typename T, template <typename> class Container>
void insertion(T *cont, int rec_level)
{
	int jacob_iteration = 1;
	std::list<element<T> > pend;
	std::list<element<T> > main;
	typename std::list<element<T> >::iterator tmp_it;
	element<T> odd;

	// Initialize the main and pend lists
	initMain<T, Container>(main, cont, rec_level);
	odd = initPend<T, Container>(&pend, cont, rec_level);

	// Insert B1 into main
	main->insert(main->begin(), pend.front());
	pend.pop_front();

	while (!pend.empty()) {
		typename std::list<element<T> >::iterator insert = pend.begin();
		size_t insertions = jacobsthal(jacob_iteration) - jacobsthal(jacob_iteration - 1);
		if (insertions > pend.size())
			insertions = pend.size();
		std::advance(insert, insertions - 1);
		for (; insertions > 0; insertions--) {
			typename std::list<element<T> >::iterator boundary = main->begin();
			while (boundary->tag != insert->tag)
				boundary++;
			typename std::list<element<T> >::iterator slot = binarySearch<T>(*main, insert->content.back(), boundary);
			main->insert(slot, *insert);
			tmp_it = insert;
			tmp_it--;
			pend.erase(insert);
			insert = tmp_it;
		}
		jacob_iteration++;
	}

	// Insert the odd element
	if (odd.tag != 0) {
		typename std::list<element<T> >::iterator slot = binarySearch<T>(*main, odd.content.back(), main->end());
		main->insert(slot, odd);
	}

	// Copy the sorted elements back to one vector
	std::vector<int> new_cont;
	typename std::list<element<T> >::iterator it = main->begin();
	while (it != main->end()) {
		std::copy(it->content.begin(), it->content.end(), std::back_inserter(new_cont));
		it++;
	}
	// Copy the leftover elements
	std::copy(cont->end() - (cont ->size() % (1 << rec_level)), cont->end(), std::back_inserter(new_cont));
	*cont = new_cont;

	if (rec_level == 0)
		return;
	insertion<T, Container>(cont, rec_level - 1);
}

// first face of the algorithm
template <typename T, template <typename> class Container>
void pairSortRec(T *cont, unsigned int *rec_level)
{
	if (pow(2, *rec_level) > cont->size() / 2)
		return;

	typename T::iterator it = cont->begin() + pow(2, *rec_level) - 1;
	typename T::iterator it2 = cont->begin() + pow(2, *rec_level + 1) - 1;
	typename T::iterator decoy1;
	typename T::iterator decoy2;

	while (it2 != cont->end())
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
		if (!safeIter(&it2, cont->end(), pow(2, *rec_level + 1)))
			break;
		it += pow(2, *rec_level + 1);
	}

	(*rec_level)++;
	pairSortRec(cont, rec_level);
}

// Algorithm with vector
template <typename T>
double PmergeMe(T *cont) {
	unsigned int rec_level = 0;
	clock_t start = clock();

	pairSortRec(cont, &rec_level);
	insertion(cont, rec_level);

	clock_t end = clock();
	return (static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000);
}

#endif
