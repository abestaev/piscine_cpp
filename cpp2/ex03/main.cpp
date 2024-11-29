#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.hpp"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

int main( void ) {
    Point A(0.0, 0.0), B(10.0, 10.0), C(0.0, 20.0);
    Point P(9, 10);

    std::cout << "Point A: " << A.getX() << ", " << A.getY() << std::endl;
    std::cout << "Point B: " << B.getX() << ", " << B.getY() << std::endl;
    std::cout << "Point C: " << C.getX() << ", " << C.getY() << std::endl;
    std::cout << "Point P: " << P.getX() << ", " << P.getY() << std::endl;

    std::cout << "Area of ABC: " << Area(A, B, C) << std::endl;
    std::cout << std::boolalpha;
    if (bsp(A, B, C, P))
        std::cout << "Is P inside ABC? " << GREEN << bsp(A, B, C, P) << RESET << std::endl;
    else
        std::cout << "Is P inside ABC? " << RED << bsp(A, B, C, P) << RESET << std::endl;
    return 0;
}