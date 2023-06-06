#include "game/render.hpp"
#include "game/bullet.hpp"
#include "utils/render_circle.hpp"


void game::render_bullets()
{
    auto& _bullets = bullets();
    for(auto bullet : _bullets) {
        Point pos {
            static_cast<int>(bullet.pos.x),
            static_cast<int>(bullet.pos.y)
        };

        SDL_SetRenderDrawColor(rnd, 0, 127, 255, 255);
    #ifdef __EMSCRIPTEN__
        int radius = bullet.size();
        SDL_Rect area {
            pos.x - radius,
            pos.y - radius,
            radius * 2,
            radius * 2
        };
        SDL_RenderFillRect(rnd, &area);

        SDL_SetRenderDrawColor(rnd, 0, 0, 0, 255);
        SDL_RenderDrawRect(rnd, &area);
    #else
        render_fill_circle(rnd, pos, bullet.size());

        SDL_SetRenderDrawColor(rnd, 0, 0, 0, 255);
        render_draw_circle(rnd, pos, bullet.size());
    #endif
    }
}

