#include "game/render.hpp"
#include "game/timeline.hpp"
#include "utils/screen.hpp"


void game::render_overlay_clock()
{
    auto screen = screen_size();

    SDL_Rect area {
        0, 0,
        screen.x,
        16
    };

    float p = 1 - 1.0f * level_time / duel_time;
    if(p > 0) {
        area.w *= p;
        SDL_SetRenderDrawColor(rnd, 0, 255, 255, 255);
    } else {
        p = 1 - 1.0f * (level_time - duel_time)
                     / (duel_timeout - duel_time);
        area.w *= p;
        SDL_SetRenderDrawColor(rnd, 255, 0, 0, 255);
    }

    SDL_RenderFillRect(rnd, &area);
}

