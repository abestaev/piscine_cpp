#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        Point();
        Point(float const x, float const y);
        Point(Point const &p);

        Point &operator=(Point const &other);

        ~Point();

        Fixed getY() const;
        Fixed getX() const;
}