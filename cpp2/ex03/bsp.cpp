#include "Point.hpp"

float Area(Point const a, Point const b, Point const c)
{
    return std::abs((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
                     b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
                     c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0f);
}

static bool onEdge(Point const a, Point const point)
{
    if (a.getX() == point.getX() && a.getY() == point.getY())
        return true;
    return false;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float abc = Area(a, b, c);
    float abp = Area(a, b, point);
    float acp = Area(a, c, point);
    float bcp = Area(b, c, point);
    // std::cout << "ABC: " << abc << " ABP: " << abp << " ACP: " << acp << " BCP: " << bcp << std::endl;
    if (abp == 0 || acp == 0 || bcp == 0 || onEdge(a, point) || onEdge(b, point) || onEdge(c, point))
        return false;    
    // std::cout << "ABC: " << abc << " Somme: "<< abp + acp + bcp << std::endl;
    return abc == abp + acp + bcp;
}