#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <ctime>
#include <sstream>

class PmergeMe {
    private: 
        
        std::vector<int>    recursiveSortVector(std::vector<int>& vec, int depth);
        std::vector<int>    mergeVector(const std::vector<int>& left, const std::vector<int>& right);
        int                 binarySearchVector(const std::vector<int>& vec, int target, int limit);
        std::vector<int>    generateJacobsthalSequenceVector(int n);

    public:
        PmergeMe();
        PmergeMe(PmergeMe const &other);
        PmergeMe &operator=(PmergeMe const &other);
        ~PmergeMe();

        void printVector(const std::vector<int>& vec);
        void printDeque(const std::deque<int>& deq);

        std::vector<int> mergeInsertSortVector(const std::vector<int>& input);
        std::deque<int> mergeInsertSort(const std::deque<int>& input);
};

#endif