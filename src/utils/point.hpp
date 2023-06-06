#ifndef INCLUDE_UTILS_POINT_HPP
#define INCLUDE_UTILS_POINT_HPP

#include <SDL2/SDL_rect.h>

typedef SDL_Point Point;
typedef SDL_FPoint FPoint;

constexpr bool operator == (Point const& a,
                            Point const& b)
{
    return a.x == b.x && a.y == b.y;
}

constexpr bool operator != (Point const& a,
                            Point const& b)
{
    return !(a == b);
}

constexpr bool operator == (FPoint const& a,
                            FPoint const& b)
{
    if(std::abs(a.x - b.x) < 0.001)
        if(std::abs(a.y - b.y) < 0.001)
            return true;
    return false;
}

constexpr bool operator != (FPoint const& a,
                            FPoint const& b)
{
    return !(a == b);
}

constexpr Point operator + (Point a, Point const& b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

constexpr Point operator - (Point a, Point const& b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}


constexpr FPoint operator + (FPoint a, FPoint const& b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

constexpr FPoint operator - (FPoint a, FPoint const& b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

#endif // INCLUDE_UTILS_POINT_HPP
