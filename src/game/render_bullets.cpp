#include "game/render.hpp"
#include "game/bullet.hpp"
#include "utils/render_circle.hpp"


void game::render_bullets()
{
    auto _bullets = bullets();
    for(auto bullet : _bullets) {
        SDL_SetRenderDrawColor(rnd, 0, 127, 255, 255);

        Point pos {
            static_cast<int>(bullet.pos.x),
            static_cast<int>(bullet.pos.y)
        };

        render_fill_circle(rnd, pos, bullet.size());

        SDL_SetRenderDrawColor(rnd, 0, 0, 0, 255);
        render_draw_circle(rnd, pos, bullet.size());
    }
}

