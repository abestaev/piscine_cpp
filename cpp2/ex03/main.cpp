#include "Fixed.hpp"

int main( void ) {
    Fixed a(5.5f);
    Fixed b(2);
    Fixed c;

    std::cout << "Variables:\na: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;

    // Test des opérateurs de comparaison
    std::cout << "\nComparaison:" << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;

    // Test des opérateurs arithmétiques
    std::cout << "\nOpérations arithmétiques:" << std::endl;
    std::cout << "a + b: " << (a + b) << std::endl;
    std::cout << "a - b: " << (a - b) << std::endl;
    std::cout << "a * b: " << (a * b) << std::endl;
    std::cout << "a / b: " << (a / b) << std::endl;

    // Test des incrémentations et décrémentations
    std::cout << "\nIncrémentation et décrémentation:" << std::endl;
    std::cout << "c (avant): " << c << std::endl;
    std::cout << "++c: " << ++c << std::endl;
    std::cout << "c++: " << c++ << std::endl;
    std::cout << "c (après incrémentation): " << c << std::endl;

    std::cout << "--c: " << --c << std::endl;
    std::cout << "c--: " << c-- << std::endl;
    std::cout << "c (après décrémentation): " << c << std::endl;

    const Fixed d(3.3f);
    const Fixed e(7.7f);

    std::cout << "\nMin et Max:" << std::endl;
    std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
    std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
    std::cout << "min(d, e): " << Fixed::min(d, e) << std::endl;
    std::cout << "max(d, e): " << Fixed::max(d, e) << std::endl;

    return 0;
}