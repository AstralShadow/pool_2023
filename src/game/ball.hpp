#ifndef INCLUDE_GAME_BALL_HPP
#define INCLUDE_GAME_BALL_HPP

#include "utils/point.hpp"
#include <vector>
#include <set>
#include <functional>

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

    void ball_toggle_cueable(int);
    bool is_ball_cueable(int);

    int get_closest_ball(Point pos);
    int get_closest_ball(FPoint pos);
    int get_closest_cueable_ball(Point pos);
    int get_closest_cueable_ball(FPoint pos);


    void create_ball(Point pos);
    void render_balls();

}

#endif // INCLUDE_GAME_BALL_HPP
