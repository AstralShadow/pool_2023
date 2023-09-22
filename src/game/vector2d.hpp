#ifndef INCLUDE_GAME_VECTOR2D_HPP
#define INCLUDE_GAME_VECTOR2D_HPP

#include "utils/pi.hpp"
#include <cmath>

using std::sin;
using std::cos;
using std::atan2;
using std::sqrt;


namespace game
{
    struct Vector2D
    {
        float angle = 0;
        float length = 0;

        float x() const { return cos(angle) * length; }
        float y() const { return sin(angle) * length; }


        static Vector2D from_components(float, float);

        template<typename TPoint>
        static Vector2D from_components(TPoint p)
        {
            return from_components(p.x, p.y);
        }


        Vector2D operator + (Vector2D o) const;
        Vector2D& operator += (Vector2D);

        Vector2D operator - (Vector2D v) const
            { return *this + (-v); }
        Vector2D& operator -= (Vector2D v)
            { return (*this += -v); }

        Vector2D operator - () const
        {
            Vector2D v = *this;
            v.angle += pi_f();
            return v;
        }
    };

}

#endif // INCLUDE_GAME_VECTOR2D_HPP
