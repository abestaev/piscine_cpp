#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>
#include <climits>
#include <iomanip>
#include <sys/time.h>
#include "PmergeMe.hpp"

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

    // Vérification des arguments
    std::vector<int> numbers;
    for (int i = 1; i < argc; ++i) {
        int val;
        std::stringstream ss(argv[i]);
        if (!(ss >> val) || !ss.eof() || val < 0 || val > INT_MAX) {
            std::cerr << "Error: Invalid number '" << argv[i] << "'" << std::endl;
            return 1;
        }
        numbers.push_back(val);
    }

    const size_t MAX_DISPLAY = 5;
    // Affichage avant tri
    std::cout << "Before: ";
    size_t i = 0;
    while (i < numbers.size() && i < MAX_DISPLAY)
        std::cout << numbers[i++] << " ";
    if (numbers.size() > MAX_DISPLAY)
        std::cout << "[...]";

    // Mesure du temps d'exécution du tri merge-insert
    std::cout << std::endl;
    long long start = getCurrentTimeMicros();
    PmergeMe sorter;
    std::vector<int> sorted = sorter.mergeInsertSortVector(numbers);
    long long end = getCurrentTimeMicros();
    long long elapsed = end - start;


    // Affichage après tri
    std::cout << "After:  ";
    i = 0;
    while (i < sorted.size() && i < MAX_DISPLAY)
        std::cout << sorted[i++] << " ";
    if (sorted.size() > MAX_DISPLAY)
        std::cout << "[...]";
    std::cout << std::endl;


    // Affichage des résultats de performance
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Time to process a range of " << numbers.size() 
              << " elements with std::vector: " << elapsed << " us" << std::endl;
    return 0;
}
