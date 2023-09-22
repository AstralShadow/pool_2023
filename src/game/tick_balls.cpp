#include "game/ball.hpp"
#include <iostream>

using std::cout;
using std::flush;
using std::endl;

using std::max;
using std::min;


void game::tick_balls(u32 ms)
{
    float t = ms / 1000.0f;

    for(auto& ball : balls()) {
        auto& motion = ball.motion;
        auto& speed = motion.length;
        auto old_speed = speed;

        speed -= t * 500;

        if(speed < 5) {
            speed = 0;
            continue;
        }

        cout << "L " << speed << "   \r" << flush;

        auto movement = motion;
        movement.length = min((speed + old_speed) / 2, 1500.0f);
        FPoint delta {
            movement.x() * t,
            movement.y() * t
        };
        ball.pos = ball.pos + delta;
    }
}

