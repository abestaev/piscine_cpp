#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <ctime>
#include <sstream>

class PmergeMe {
    private: 
        void printVector(const std::vector<int>& vec);
        std::vector<int> recursiveSort(std::vector<int>& vec, int depth);
        std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right);

    public:
        PmergeMe();
        PmergeMe(PmergeMe const &other);
        PmergeMe &operator=(PmergeMe const &other);
        ~PmergeMe();

        std::vector<int> mergeInsertSort(const std::vector<int>& input);

};

#endif