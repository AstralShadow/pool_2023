#include "game.hpp"
#include "ball.hpp"
#include <SDL2/SDL_events.h>
#include <iostream>

using std::cout;
using std::endl;


void game::
mouseup(SDL_MouseButtonEvent& ev, scene_uid)
{

}

void game::
mousedown(SDL_MouseButtonEvent& ev, scene_uid)
{
    // Add/Modify balls
    if(ev.button == SDL_BUTTON_RIGHT) {
        auto const& balls = game::balls();

        Point pos = {ev.x, ev.y};
        int closest = -1;
        float closest_dist2;

        for(int i = 0; i < balls.size(); i++) {
            auto const& ball = balls[i];

            Point delta {
                ball.pos.x - pos.x,
                ball.pos.y - pos.y
            };

            float dist2 = delta.x * delta.x
                        + delta.y * delta.y;

            if(closest == -1 || dist2 < closest_dist2) {
                closest = i;
                closest_dist2 = dist2;
            }
        }

        // Squared range for cueable-switch to activate
        int min_range2 = 48 * 48;

        if(closest == -1 || closest_dist2 > min_range2) {
            create_ball({ev.x, ev.y});
            cout << "Summon thee ball at "
                 << ev.x << "x" << ev.y << endl;
        } else {
            auto& bset = cueable_balls();
            if(bset.find(closest) == bset.end())
                bset.insert(closest);
            else
                bset.erase(closest);
        }
    }
}

void game::
mouse_motion(SDL_MouseMotionEvent& ev, scene_uid)
{

}

