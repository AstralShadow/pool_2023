#include "game/ball.hpp"


bool game::is_ball_cuable(int index)
{
    auto const& _set = cueable_balls();

    return _set.find(index) != _set.end();
}


void game::ball_toggle_cuable(int index)
{
    auto& _set = cueable_balls();

    if(is_ball_cuable(index))
        _set.erase(index);
    else
        _set.insert(index);
}

