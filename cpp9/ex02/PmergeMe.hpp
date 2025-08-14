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

    public:
        PmergeMe();
        PmergeMe(PmergeMe const &other);
        PmergeMe &operator=(PmergeMe const &other);
        ~PmergeMe();

        std::vector<int> mergeInsertSort(const std::vector<int>& input);
};

#endif