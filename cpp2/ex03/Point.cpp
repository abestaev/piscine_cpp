#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Point::Point(float const x, float const y): _x(x), _y(y) {
    // std::cout << "Parametric constructor called" << std::endl;
}

Point::Point(Point const &p): _x(p._x), _y(p._y) {
    // std::cout << "Copy constructor called" << std::endl;
}

Point &Point::operator=(Point const &other) {
    (void)other;
    // std::cout << "Assignation operator called (has no effect)" << std::endl;
    return *this;
}

Point::~Point() {
    // std::cout << "Destructor called" << std::endl;
}

Fixed Point::getY() const {
    return _y;
}

Fixed Point::getX() const {
    return _x;
}