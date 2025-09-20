#include "PmergeMe.hpp"
#include <set>
#include <climits>

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

void PmergeMe::printDeque(const std::deque<int> &deq) {
    std::cout << "Deque content: ";
    for (size_t i = 0; i < deq.size(); ++i) {
        std::cout << deq[i] << (i < deq.size() - 1 ? " " : "");
    }
    std::cout << std::endl;
}

std::vector<int> PmergeMe::mergeVector(const std::vector<int>& left, const std::vector<int>& right) {
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

std::vector<int> PmergeMe::recursiveSortVector(std::vector<int>& vec, int depth) {
    if (vec.size() <= 1)
        return vec;
    size_t mid = vec.size() / 2;
    std::vector<int> left(vec.begin(), vec.begin() + mid);
    std::vector<int> right(vec.begin() + mid, vec.end());
    left = recursiveSortVector(left, depth + 1);
    right = recursiveSortVector(right, depth + 1);
    std::vector<int> merged = mergeVector(left, right);
    return merged;
}

int PmergeMe::binarySearchVector(const std::vector<int>& vec, int target, int limit) {
    int left = 0;
    int right = std::min(limit, (int)vec.size() - 1);
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

std::vector<int> PmergeMe::generateJacobsthalSequenceVector(int n) {
    std::vector<int> jacobsthal;
    if (n <= 0) return jacobsthal;
    jacobsthal.push_back(1);
    if (n == 1) return jacobsthal;
    jacobsthal.push_back(3);
    while (true) {
        int next = jacobsthal.back() + 2 * jacobsthal[jacobsthal.size() - 2];
        if (next > n) break;
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}

std::vector<int> PmergeMe::mergeInsertSortVector(const std::vector<int>& input) {
    if (input.size() <= 1) return input;
    std::vector< std::pair<int,int> > pairs;
    int straggler = -1;
    bool hasStraggler = false;
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        int a = input[i];
        int b = input[i + 1];
        if (a > b) std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }
    if (input.size() % 2 != 0) {
        straggler = input.back();
        hasStraggler = true;
    }
    std::vector<int> mainChain;
    std::vector<int> pend;
    std::set< std::pair<int,int> > bigToSmall;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].second);
        bigToSmall.insert(std::make_pair(pairs[i].second, pairs[i].first));
    }
    mainChain = recursiveSortVector(mainChain, 0);
    std::vector<int> sortedBigs = mainChain;
    pend.clear();
    pend.reserve(sortedBigs.size());
    for (size_t i = 0; i < sortedBigs.size(); ++i) {
        std::set< std::pair<int,int> >::const_iterator it = bigToSmall.lower_bound(std::make_pair(sortedBigs[i], INT_MIN));
        if (it != bigToSmall.end() && it->first == sortedBigs[i])
            pend.push_back(it->second);
    }
    if (!pend.empty()) {
        mainChain.insert(mainChain.begin(), pend[0]);
    }
    if (pend.size() > 1) {
        std::vector<int> jacobsthal = generateJacobsthalSequenceVector(pend.size() - 1);
        std::vector<bool> inserted(pend.size(), false);
        inserted[0] = true;
        for (size_t i = 0; i < jacobsthal.size(); ++i) {
            int jacIndex = jacobsthal[i];
            int start = (i == 0) ? jacIndex : jacobsthal[i-1] + 1;
            for (int j = jacIndex; j >= start && j > 0; --j) {
                if (j < (int)pend.size() && !inserted[j]) {
                    int partnerPos = binarySearchVector(mainChain, sortedBigs[j], (int)mainChain.size());
                    int pos = binarySearchVector(mainChain, pend[j], partnerPos);
                    mainChain.insert(mainChain.begin() + pos, pend[j]);
                    inserted[j] = true;
                }
            }
        }
        for (size_t i = 1; i < pend.size(); ++i) {
            if (!inserted[i]) {
                int partnerPos = binarySearchVector(mainChain, sortedBigs[i], (int)mainChain.size());
                int pos = binarySearchVector(mainChain, pend[i], partnerPos);
                mainChain.insert(mainChain.begin() + pos, pend[i]);
            }
        }
    }
    if (hasStraggler) {
        int pos = binarySearchVector(mainChain, straggler, mainChain.size());
        mainChain.insert(mainChain.begin() + pos, straggler);
    }
    return mainChain;
}

std::deque<int> PmergeMe::mergeDeque(const std::deque<int>& left, const std::deque<int>& right) {
    std::deque<int> result;
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

std::deque<int> PmergeMe::recursiveSortDeque(std::deque<int>& vec, int depth) {
    if (vec.size() <= 1)
        return vec;
    size_t mid = vec.size() / 2;
    std::deque<int> left(vec.begin(), vec.begin() + mid);
    std::deque<int> right(vec.begin() + mid, vec.end());
    left = recursiveSortDeque(left, depth + 1);
    right = recursiveSortDeque(right, depth + 1);
    std::deque<int> merged = mergeDeque(left, right);
    return merged;
}

int PmergeMe::binarySearchDeque(const std::deque<int>& deq, int target, int limit) {
    int left = 0;
    int right = std::min(limit, (int)deq.size() - 1);
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (deq[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

std::deque<int> PmergeMe::generateJacobsthalSequenceDeque(int n) {
    std::deque<int> jacobsthal;
    if (n <= 0) return jacobsthal;
    jacobsthal.push_back(1);
    if (n == 1) return jacobsthal;
    jacobsthal.push_back(3);
    while (true) {
        int next = jacobsthal.back() + 2 * jacobsthal[jacobsthal.size() - 2];
        if (next > n) break;
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}

std::deque<int> PmergeMe::mergeInsertSortDeque(const std::deque<int>& input) {
    if (input.size() <= 1) return input;
    std::deque< std::pair<int,int> > pairs;
    int straggler = -1;
    bool hasStraggler = false;
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        int a = input[i];
        int b = input[i + 1];
        if (a > b) std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }
    if (input.size() % 2 != 0) {
        straggler = input.back();
        hasStraggler = true;
    }
    std::deque<int> mainChain;
    std::deque<int> pend;
    std::set< std::pair<int,int> > bigToSmallDeq;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].second);
        bigToSmallDeq.insert(std::make_pair(pairs[i].second, pairs[i].first));
    }
    mainChain = recursiveSortDeque(mainChain, 0);
    std::deque<int> sortedBigsDeq = mainChain;
    pend.clear();
    for (size_t i = 0; i < sortedBigsDeq.size(); ++i) {
        std::set< std::pair<int,int> >::const_iterator it = bigToSmallDeq.lower_bound(std::make_pair(sortedBigsDeq[i], INT_MIN));
        if (it != bigToSmallDeq.end() && it->first == sortedBigsDeq[i])
            pend.push_back(it->second);
    }
    if (!pend.empty())
        mainChain.insert(mainChain.begin(), pend[0]);
    if (pend.size() > 1) {
        std::deque<int> jacobsthal = generateJacobsthalSequenceDeque(pend.size() - 1);
        std::deque<bool> inserted(pend.size(), false);
        inserted[0] = true;
        for (size_t i = 0; i < jacobsthal.size(); ++i) {
            int jacIndex = jacobsthal[i];
            int start = (i == 0) ? jacobsthal[i] : jacobsthal[i-1] + 1;
            for (int j = jacIndex; j >= start && j > 0; --j) {
                if (j < (int)pend.size() && !inserted[j]) {
                    int partnerPos = binarySearchDeque(mainChain, sortedBigsDeq[j], (int)mainChain.size());
                    int pos = binarySearchDeque(mainChain, pend[j], partnerPos);
                    mainChain.insert(mainChain.begin() + pos, pend[j]);
                    inserted[j] = true;
                }
            }
        }
        for (size_t i = 1; i < pend.size(); ++i) {
            if (!inserted[i]) {
                int partnerPos = binarySearchDeque(mainChain, sortedBigsDeq[i], (int)mainChain.size());
                int pos = binarySearchDeque(mainChain, pend[i], partnerPos);
                mainChain.insert(mainChain.begin() + pos, pend[i]);
            }
        }
    }
    if (hasStraggler) {
        int pos = binarySearchDeque(mainChain, straggler, mainChain.size());
        mainChain.insert(mainChain.begin() + pos, straggler);
    }
    return mainChain;
}
