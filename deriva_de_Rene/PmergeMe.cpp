#include "PmergeMe.hpp"

// Función de ordenamiento recursivo para vector
void mergeInsertSort(std::vector<int> &vec) {
    if (vec.size() <= 1)
        return;

    size_t mid = vec.size() / 2;
    std::vector<int> left(vec.begin(), vec.begin() + mid);
    std::vector<int> right(vec.begin() + mid, vec.end());

    mergeInsertSort(left);
    mergeInsertSort(right);

    vec.clear();
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(vec));
}

// Función de ordenamiento recursivo para deque
void mergeInsertSort(std::deque<int> &deq) {
    if (deq.size() <= 1)
        return;

    size_t mid = deq.size() / 2;
    std::deque<int> left(deq.begin(), deq.begin() + mid);
    std::deque<int> right(deq.begin() + mid, deq.end());

    mergeInsertSort(left);
    mergeInsertSort(right);

    deq.clear();
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(deq));
}

// Función pública para vector
double PmergeMe(std::vector<int> *vec) {
    clock_t start = clock();
    mergeInsertSort(*vec);
    clock_t end = clock();
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0; // ms
}

// Función pública para deque
double PmergeMe(std::deque<int> *deq) {
    clock_t start = clock();
    mergeInsertSort(*deq);
    clock_t end = clock();
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0; // ms
}
