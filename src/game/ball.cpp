#include "game/ball.hpp"
#include <iostream>

using game::Ball;

using std::cout;
using std::endl;

namespace game
{
    float Ball::size = 14;
}


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


void game::cue_ball(int _ball, Vector2D cue_vector)
{
    auto& ball = balls()[_ball];

    if(cue_vector.length > 1.0f)
        cue_vector.length = 1.0f;

    cue_vector.length *= 1500.0f;
    cout << cue_vector.length << endl;
    ball.motion += cue_vector;
}

