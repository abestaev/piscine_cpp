#include "Span.hpp"
#include <iostream>

// addNumbers usage
// 1. count, number
// 2. count, min, max

int main()
{
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    try {
        std::cout << "\033[1;3m[Subject Test]\033[0m" << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        std::cout << "\033[1;3m\n[Test with 10 000 elements]\033[0m" << std::endl;
        Span sp2 = Span(10000);
        sp2.addNumber(0);
        sp2.addNumbers(9998, 5);
        sp2.addNumber(10);

        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;

        std::cout << "\033[1;3m\n[Test with 100 000 elements]\033[0m" << std::endl;
        Span sp3 = Span(100000);
        sp3.addNumbers(5, 0, 5000);
        sp3.addNumbers(99995, 10000);

        std::cout << sp3.shortestSpan() << std::endl;
        std::cout << sp3.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error : " << e.what() << std::endl;
    }
    try {
        std::cout << "\033[1;3m\n[Limits testing: out of bounds]\033[0m" << std::endl;
        sp.addNumber(6);
    } catch (std::exception& e) {
        std::cout << "Error : " << e.what() << std::endl;
    }
    try {
        std::cout << "\033[1;3m\n[Limits testing: shortestSpan call]\033[0m" << std::endl;
        Span sp4 = Span(5);
        sp4.addNumber(6);
        std::cout << sp4.shortestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error : " << e.what() << std::endl;
    }
    return 0;
}