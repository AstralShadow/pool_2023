#include "game/get_closest_ball.hpp"


int game::get_closest_ball(Point pos)
{
    return get_closest_ball<>(pos);
}

int game::get_closest_ball(FPoint pos)
{
    return get_closest_ball<>(pos);
}


int game::get_closest_cueable_ball(Point pos)
{
    return get_closest_ball<>(pos, is_ball_cueable);
}

int game::get_closest_cueable_ball(FPoint pos)
{
    return get_closest_ball<>(pos, is_ball_cueable);
}

