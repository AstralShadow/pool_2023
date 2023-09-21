#include "game/ball.hpp"
#include "utils/types.hpp"


int game::get_closest_ball(Point pos,
        std::function<bool(Ball const&)> query)
{
    FPoint fpos {
        static_cast<float>(pos.x),
        static_cast<float>(pos.y),
    };
    return get_closest_ball(fpos, query);
}

int game::get_closest_ball(Point pos,
        std::function<bool(int)> query)
{
    FPoint fpos {
        static_cast<float>(pos.x),
        static_cast<float>(pos.y),
    };
    return get_closest_ball(fpos, query);
}


int game::get_closest_ball(FPoint pos,
        std::function<bool(Ball const&)> query)
{
    auto const balls = game::balls();

    int closest = -1;
    float closest_dist2;

    for(u32 i = 0; i < balls.size(); i++) {
        auto const& ball = balls[i];
        if(query && query(ball) == false)
            continue;

        float dist2 = ::dist2(ball.pos, pos);

        if(closest == -1 || dist2 < closest_dist2) {
            closest = i;
            closest_dist2 = dist2;
        }
    }

    return closest;
}

int game::get_closest_ball(FPoint pos,
        std::function<bool(int)> query)
{
    auto const balls = game::balls();

    int closest = -1;
    float closest_dist2;

    for(u32 i = 0; i < balls.size(); i++) {
        auto const& ball = balls[i];
        if(query(i) == false)
            continue;

        float dist2 = ::dist2(ball.pos, pos);

        if(closest == -1 || dist2 < closest_dist2) {
            closest = i;
            closest_dist2 = dist2;
        }
    }

    return closest;
}

