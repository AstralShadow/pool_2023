#include "game/render.hpp"
#include "game/ball.hpp"
#include "utils/render_circle.hpp"


void game::render_balls()
{
    SDL_SetRenderDrawColor(rnd, 0, 255, 0, 255);

    auto& balls = game::balls();
    auto& cueable = game::cueable_balls();

    for(u32 i = 0; i < balls.size(); i++) {
        auto& ball = balls[i];

        Point pos {
            static_cast<int>(ball.pos.x),
            static_cast<int>(ball.pos.y)
        };
        int size = 16;
        render_fill_circle(rnd, pos, size);

        if(cueable.find(i) != cueable.end()) {
            size += 8;
            render_draw_circle(rnd, pos, size, 1);
        }
    }
}

