#include "game/ball.hpp"
#include "utils/types.hpp"
#include <functional>

namespace game
{


using std::function;


template<typename TPoint> constexpr
FPoint _toFPoint(TPoint _pos)
{
    FPoint pos {
        static_cast<float>(_pos.x),
        static_cast<float>(_pos.y),
    };
    return pos;
}

template<> constexpr
FPoint _toFPoint<FPoint>(FPoint pos)
{
    return pos;
}


template<typename QueryIn> inline
bool _check_query(
        function<bool(QueryIn)> query,
        vector<Ball> const& balls, int index);

template<> inline
bool _check_query<int>(
        function<bool(int)> query,
        vector<Ball> const&, int index)
{
    return query(index);
}

template<> inline
bool _check_query<Ball>(
        function<bool(Ball)> query,
        vector<Ball> const& balls, int index)
{
    return query(balls[index]);
}

template<> inline
bool _check_query<Ball const&>(
        function<bool(Ball const&)> query,
        vector<Ball> const& balls, int index)
{
    return query(balls[index]);
}


template<
    typename TPoint,
    typename QueryIn = int
>
inline int get_closest_ball(
        TPoint _pos,
        function<bool(QueryIn)> query = nullptr)
{
    FPoint pos = _toFPoint(_pos);

    auto const balls = game::balls();

    int closest = -1;
    float closest_dist2;

    for(u32 i = 0; i < balls.size(); i++) {
        auto const& ball = balls[i];

        if(query)
            if(!_check_query<QueryIn>(query, balls, i))
                continue;

        float dist2 = ::dist2(ball.pos, pos);

        if(closest == -1 || dist2 < closest_dist2) {
            closest = i;
            closest_dist2 = dist2;
        }
    }

    return closest;
}

template<
    typename TPoint,
    typename FPtr
>
inline int get_closest_ball(
        TPoint _pos,
        FPtr * _query)
{
    return get_closest_ball(_pos,
            std::function<FPtr>(_query));
}


}

