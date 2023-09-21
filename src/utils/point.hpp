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


constexpr int dist2(Point a, Point b)
{
    Point delta {
        a.x - b.x,
        a.y - b.y
    };
    return delta.x * delta.x + delta.y * delta.y;
}

constexpr float dist2(FPoint a, FPoint b)
{
    FPoint delta {
        a.x - b.x,
        a.y - b.y
    };
    return delta.x * delta.x + delta.y * delta.y;
}

constexpr float dist2(FPoint a, Point b)
{
    FPoint delta {
        a.x - static_cast<float>(b.x),
        a.y - static_cast<float>(b.y)
    };
    return delta.x * delta.x + delta.y * delta.y;
}

constexpr float dist2(Point a, FPoint b)
{
    return dist2(b, a);
}

#endif // INCLUDE_UTILS_POINT_HPP
