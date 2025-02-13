#include "Span.hpp"
#include <stdexcept>
#include <algorithm>
#include <ctime>

Span::Span() : max_size(0) {}

Span::Span(unsigned int N) : max_size(N) {}

Span::Span(const Span& other) {
    *this = other;
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        this->list = other.list;
        this->max_size = other.max_size;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (list.size() >= max_size)
        throw std::length_error("Span is full");
    list.push_back(number);
}


// complexité en O(n log n)
int Span::shortestSpan() {
    if (list.size() < 2)
        throw std::logic_error("Span is too short");
    std::vector<int> sorted = list;
    std::sort(sorted.begin(), sorted.end());
    int min = sorted[1] - sorted[0];
    for (unsigned int i = 2; i < sorted.size(); i++) {
        min = std::min(min, sorted[i] - sorted[i - 1]);
    }
    return min;
}

int Span::longestSpan() {
    if (list.size() < 2)
        throw std::logic_error("Span is too short");
    int min = *std::min_element(list.begin(), list.end());
    int max = *std::max_element(list.begin(), list.end());
    return max - min;
}

void Span::addNumbers(unsigned int count, int number) {
    if (count + list.size() > max_size)
        throw std::length_error("Span max size exceeded");
    for (unsigned int i = 0; i < count; i++)
        addNumber(number);
}

void Span::addNumbers(unsigned int count, int min, int max) {
    if (count + list.size() > max_size)
        throw std::length_error("Span max size exceeded");
    std::srand(std::time(0));
    for (unsigned int i = 0; i < count; i++)
        list.push_back(std::rand() % (max - min) + min);
}