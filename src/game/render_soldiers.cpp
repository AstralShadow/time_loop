#include "game/render.hpp"
#include "game/soldier.hpp"
#include "utils/render_circle.hpp"


void game::render_soldiers()
{
    for(auto soldier : soldiers()) {
        SDL_SetRenderDrawColor(rnd, 0, 255, 0, 255);

        Point pos {
            static_cast<int>(soldier.pos.x),
            static_cast<int>(soldier.pos.y)
        };

        render_fill_circle(rnd, pos, soldier.size());
    }
}

