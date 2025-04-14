#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <algorithm>

// Funciones principales
double PmergeMe(std::vector<int> *vec);
double PmergeMe(std::deque<int> *deq);

// Funciones internas para merge-insert sort
void mergeInsertSort(std::vector<int> &vec);
void mergeInsertSort(std::deque<int> &deq);

#endif
