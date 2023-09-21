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

    void ball_toggle_cuable(int);
    bool is_ball_cuable(int);


    void create_ball(Point pos);
    void render_balls();


    int get_closest_ball(Point pos,
            std::function<bool(Ball const&)> = 0);
    int get_closest_ball(FPoint pos,
            std::function<bool(Ball const&)> = 0);

    int get_closest_ball(Point pos,
            std::function<bool(int)>);
    int get_closest_ball(FPoint pos,
            std::function<bool(int)>);
}


#endif // INCLUDE_GAME_BALL_HPP
