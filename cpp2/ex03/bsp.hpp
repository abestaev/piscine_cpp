#ifndef BSP_HPP
# define BSP_HPP

#include "Point.hpp"

float Area (Point const a, Point const b, Point const c);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif