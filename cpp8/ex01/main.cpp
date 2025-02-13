#include "Span.hpp"
#include <iostream>

int main()
{
    std::cout << "\033[1;3m[Subject Test]\033[0m" << std::endl;
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "\033[1;3m\n[Test with 10 000 elements]\033[0m" << std::endl;

    Span sp2 = Span(10000);
    sp2.addNumber(0);
    sp2.addNumbers(9998, 5);
    sp2.addNumber(11);

    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;

    std::cout << "\033[1;3m\n[Test with 100 000 elements]\033[0m" << std::endl;

    Span sp3 = Span(100000);
    sp3.addNumber(0);
    sp3.addNumbers(99998, 5);
    sp3.addNumber(11);

    std::cout << sp3.shortestSpan() << std::endl;
    std::cout << sp3.longestSpan() << std::endl;

    return 0;


    //test with 10 000 and 100 000 numbers;
}