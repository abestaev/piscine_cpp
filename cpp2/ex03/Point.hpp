#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class Point 
{
    private:
        float _x;
        float _y;
    
    public:
        Point();
        Point(const Point &point);
        Point(const float x, const float y);
        ~Point();
        Point &operator=(const Point &point);

    
}

#endif