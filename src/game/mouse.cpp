#include "game/game.hpp"
#include "game/ball.hpp"
#include "game/mouse.hpp"
#include "utils/screen.hpp"
#include <SDL2/SDL_events.h>
#include <iostream>

using std::cout;
using std::endl;

using std::min;
using std::abs;


namespace game
{
    MouseMode mouse_mode = MM_NONE;

    Point drag_start {0, 0};
    Point mouse_pos {0, 0};
    int cue_target = -1;
}


void game::
mousedown(SDL_MouseButtonEvent& ev, scene_uid)
{
    mouse_pos.x = ev.x;
    mouse_pos.y = ev.y;

    Point pos = {ev.x, ev.y};
    int snap_range2 = 48 * 48; // squared

    // Cue ball
    if(ev.button == SDL_BUTTON_LEFT) {
        auto const& balls = game::balls();

        int closest = get_closest_cueable_ball(pos);
        if(closest == -1)
            return;

        float dist2 = ::dist2(pos, balls[closest].pos);

        if(dist2 < snap_range2) {
            mouse_mode = MM_CUE;
            drag_start = pos;
            cue_target = closest;
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
            ball_toggle_cueable(closest);
    }
}


static float distance_to_screen_edge(Point p)
{
    auto screen = screen_size();

    return min(min(
        abs(p.x),
        abs(p.y)
    ), min(
        abs(screen.x - p.x),
        abs(screen.y - p.y)
    ));
}

void game::
mouseup(SDL_MouseButtonEvent& ev, scene_uid)
{
    mouse_pos.x = ev.x;
    mouse_pos.y = ev.y;

    if(mouse_mode == MM_CUE)
    if(ev.button == SDL_BUTTON_LEFT) {
        auto cue_vector = Vector2D
            ::from_components(mouse_pos - drag_start);

        auto dist = distance_to_screen_edge(drag_start);
        if(dist > 60.0f)
            dist = 60.0f;
        cue_vector.length *= 3 / (dist * 2);

        cue_ball(cue_target, -cue_vector);

        mouse_mode = MM_NONE;
        cue_target = -1;
    }
}


void game::
mouse_motion(SDL_MouseMotionEvent& ev, scene_uid)
{
    mouse_pos.x = ev.x;
    mouse_pos.y = ev.y;
}

