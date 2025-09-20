#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>
#include <climits>
#include <iomanip>
#include <sys/time.h>
#include "PmergeMe.hpp"
#include <set>

 long long getCurrentTimeMicros() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000LL + tv.tv_usec;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: At least one integer argument required" << std::endl;
        return 1;
    }
    std::vector<int> numbersVec;
    std::deque<int> numbersDeq;
    std::set<int> unique_checker;
    for (int i = 1; i < argc; ++i) {
        long long val;
        std::stringstream ss(argv[i]);
        if (!(ss >> val) || !ss.eof() || val < 0) {
            std::cerr << "Error: Invalid number '" << argv[i] << "'" << std::endl;
            return 1;
        }
        if (val > INT_MAX) {
             std::cerr << "Error: Number '" << argv[i] << "' is too large." << std::endl;
             return 1;
        }
        if (!unique_checker.insert(static_cast<int>(val)).second) {
            std::cerr << "Error: Duplicate number '" << val << "' found." << std::endl;
            return 1;
        }
        numbersVec.push_back(static_cast<int>(val));
        numbersDeq.push_back(static_cast<int>(val));
    }
    const size_t MAX_DISPLAY = 20;
    std::cout << "Before: ";
    size_t i = 0;
    while (i < numbersVec.size() && i < MAX_DISPLAY)
        std::cout << numbersVec[i++] << " ";
    if (numbersVec.size() > MAX_DISPLAY)
        std::cout << "[...]";
    std::cout << std::endl;
    PmergeMe sorter;
    long long startVec = getCurrentTimeMicros();
    std::vector<int> sortedVec = sorter.mergeInsertSortVector(numbersVec);
    long long endVec = getCurrentTimeMicros();
    long long elapsedVec = endVec - startVec;
    long long startDeq = getCurrentTimeMicros();
    std::deque<int> sortedDeq = sorter.mergeInsertSortDeque(numbersDeq);
    long long endDeq = getCurrentTimeMicros();
    long long elapsedDeq = endDeq - startDeq;
    std::cout << "After:  ";
    i = 0;
    while (i < sortedVec.size() && i < MAX_DISPLAY)
        std::cout << sortedVec[i++] << " ";
    if (sortedVec.size() > MAX_DISPLAY)
        std::cout << "[...]";
    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Time to process a range of " << numbersVec.size()
              << " elements with std::vector: " << elapsedVec << " us" << std::endl;
    std::cout << "Time to process a range of " << numbersDeq.size()
              << " elements with std::deque:  " << elapsedDeq << " us" << std::endl;
    return 0;
}
