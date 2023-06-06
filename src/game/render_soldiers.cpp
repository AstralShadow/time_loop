#include "game/render.hpp"
#include "game/soldier.hpp"
#include "utils/render_circle.hpp"


void game::render_soldiers()
{
    auto& _soldiers = soldiers();
    u32 size = _soldiers.size();
    u32 i = 0;
    for(auto soldier : _soldiers) {
        u8 green = 96 + 64 * i++ / size;
        if(i == size)
            green = 255;

        SDL_SetRenderDrawColor(rnd, 0, green, 0, 255);

        Point pos {
            static_cast<int>(soldier.pos.x),
            static_cast<int>(soldier.pos.y)
        };

        render_fill_circle(rnd, pos, soldier.size());

        SDL_SetRenderDrawColor(rnd, 0, 0, 0, 255);
        render_draw_circle(rnd, pos, soldier.size());
    }
}

