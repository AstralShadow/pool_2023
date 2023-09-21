#ifndef INCLUDE_GAME_BALL_HPP
#define INCLUDE_GAME_BALL_HPP

#include "utils/point.hpp"
#include <vector>
#include <set>

using std::vector;
using std::set;


namespace game
{
    struct Ball
    {
        FPoint pos;
    };

    vector<Ball>& balls();
    set<int>& cueable_balls();


    void create_ball(Point pos);
    void render_balls();
}

#endif // INCLUDE_GAME_BALL_HPP
