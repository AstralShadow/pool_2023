#include "game/ball.hpp"

using game::Ball;


vector<Ball>& game::balls()
{
    static vector<Ball> _balls;
    return _balls;
}

set<int>& game::cueable_balls()
{
    static set<int> _cueable_balls;
    return _cueable_balls;
}


void game::create_ball(Point pos)
{
    Ball ball;
    ball.pos = {
        static_cast<float>(pos.x),
        static_cast<float>(pos.y)
    };

    balls().push_back(ball);
}

