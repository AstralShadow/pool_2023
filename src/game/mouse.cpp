#include "game/game.hpp"
#include "game/ball.hpp"
#include "game/mouse.hpp"
#include <SDL2/SDL_events.h>
#include <iostream>

using std::cout;
using std::endl;


namespace game
{
    MouseMode mouse_mode = MM_NONE;

    Point drag_start {0, 0};
}


void game::
mousedown(SDL_MouseButtonEvent& ev, scene_uid)
{
    Point pos = {ev.x, ev.y};
    int snap_range2 = 48 * 48; // squared

    // Cue ball
    if(ev.button == SDL_BUTTON_LEFT) {
        auto const& balls = game::balls();

        int closest = get_closest_ball
            (pos, is_ball_cuable);
        if(closest == -1)
            return;

        float dist2 = ::dist2(pos, balls[closest].pos);

        if(dist2 < snap_range2) {
            mouse_mode = MM_CUE;
            drag_start = pos;
        }
    }

    // Add/Modify balls
    if(ev.button == SDL_BUTTON_RIGHT) {
        auto const& balls = game::balls();

        int closest = get_closest_ball(pos);
        if(closest == -1) {
            create_ball({ev.x, ev.y});
            return;
        }

        float dist2 = ::dist2(pos, balls[closest].pos);

        if(closest == -1 || dist2 > snap_range2)
            create_ball({ev.x, ev.y});
        else
            ball_toggle_cuable(closest);
    }
}

void game::
mouseup(SDL_MouseButtonEvent& , scene_uid)
{

}


void game::
mouse_motion(SDL_MouseMotionEvent& , scene_uid)
{

}

