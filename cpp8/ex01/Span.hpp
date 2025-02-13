#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span {
    private:
        std::vector<int> list;
        unsigned int max_size;
        Span();

    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int number);
        int shortestSpan();
        int longestSpan();
        void addNumbers(int count, int number);
};

#endif