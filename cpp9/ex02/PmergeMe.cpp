#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    (void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    (void)other;
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::printVector(const std::vector<int> &vec) {
    std::cout << "Vector content: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << (i < vec.size() - 1 ? " " : "");
    }
    std::cout << std::endl;
}

std::vector<int> PmergeMe::mergeInsertSort(const std::vector<int>& input){
    std::cout << "input vector received: " << std::endl;
    printVector(input);
    
    return input;
}