#include "game/vector2d.hpp"
#include <cmath>

using game::Vector2D;


Vector2D Vector2D::from_components(float x, float y)
{
    Vector2D vec;
    vec.angle = atan2(y, x);
    vec.length = sqrt(y * y + x * x);
    return vec;
}

Vector2D Vector2D::operator + (Vector2D other) const
{
    float x = this->x() + other.x();
    float y = this->y() + other.y();
    return from_components(x, y);
}

Vector2D& Vector2D::operator += (Vector2D other)
{
    auto result = *this + other;
    return *this = result;
}

