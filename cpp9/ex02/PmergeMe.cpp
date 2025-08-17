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

std::vector<int> PmergeMe::merge(const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int> result;
    size_t i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j])
            result.push_back(left[i++]);
        else
            result.push_back(right[j++]);
    }
    while (i < left.size()) result.push_back(left[i++]);
    while (j < right.size()) result.push_back(right[j++]);

    return result;
}

std::vector<int> PmergeMe::recursiveSort(std::vector<int>& vec, int depth) {
    if (vec.size() <= 1)
        return vec;

    size_t mid = vec.size() / 2;
    std::vector<int> left(vec.begin(), vec.begin() + mid);
    std::vector<int> right(vec.begin() + mid, vec.end());

    std::cout << std::string(depth * 2, ' ')
              << "Divise en : [ ";
    for (size_t i = 0; i < left.size(); ++i) std::cout << left[i] << " ";
    std::cout << "] et [ ";
    for (size_t i = 0; i < right.size(); ++i) std::cout << right[i] << " ";
    std::cout << "]" << std::endl;

    left = recursiveSort(left, depth + 1);
    right = recursiveSort(right, depth + 1);

    std::vector<int> merged = merge(left, right);

    std::cout << std::string(depth * 2, ' ')
              << "Fusion donne : [ ";
    for (size_t i = 0; i < merged.size(); ++i) std::cout << merged[i] << " ";
    std::cout << "]" << std::endl;

    return merged;
}

std::vector<int> PmergeMe::mergeInsertSort(const std::vector<int>& input) {
    std::vector< std::pair<int,int> > pairs;

    std::cout << "Formation des paires :" << std::endl;
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        int a = input[i];
        int b = input[i + 1];
        if (a > b) std::swap(a, b);

        std::cout << "  Paire (" << a << ", " << b << ")" << std::endl;
        pairs.push_back(std::make_pair(a, b));
    }
    if (input.size() % 2 != 0) {
        std::cout << "  Dernier element non paire : " << input.back() << std::endl;
        pairs.push_back(std::make_pair(input.back(), input.back()));
    }

    // Construire mainChain (les grands) et pend (les petits)
    std::vector<int> mainChain;
    std::vector<int> pend;
    for (size_t i = 0; i < pairs.size(); ++i) {
        pend.push_back(pairs[i].first);
        mainChain.push_back(pairs[i].second);
    }

    std::cout << "\nMainChain avant tri : [ ";
    for (size_t i = 0; i < mainChain.size(); ++i) std::cout << mainChain[i] << " ";
    std::cout << "]" << std::endl;

    std::cout << "Pend (les petits) : [ ";
    for (size_t i = 0; i < pend.size(); ++i) std::cout << pend[i] << " ";
    std::cout << "]" << std::endl;

    // Tri récursif de mainChain
    std::cout << "\n--- Tri récursif de MainChain ---" << std::endl;
    mainChain = recursiveSort(mainChain, 0);

    // Étape Ford-Johnson : insérer au début le "pendant" du plus petit grand
    int firstMain = mainChain.front();
    int pairedSmall = -1;
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].second == firstMain) {
            pairedSmall = pairs[i].first;
            break;
        }
    }
    if (pairedSmall != -1) {
        std::cout << "\nInsertion speciale : " << pairedSmall
                  << " (pendant de " << firstMain
                  << ") au debut de la MainChain." << std::endl;
        mainChain.insert(mainChain.begin(), pairedSmall);
    }

    // Résultat final intermédiaire
    std::cout << "\n=== Résultat après insertion initiale ===" << std::endl;
    std::cout << "MainChain : [ ";
    for (size_t i = 0; i < mainChain.size(); ++i) std::cout << mainChain[i] << " ";
    std::cout << "]" << std::endl;

    std::cout << "Pend restant : [ ";
    for (size_t i = 0; i < pend.size(); ++i) {
        if (pend[i] != pairedSmall) std::cout << pend[i] << " ";
    }
    std::cout << "]" << std::endl;

    return mainChain;
}
