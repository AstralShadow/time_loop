#include "game/render.hpp"
#include "utils/screen.hpp"
#include "core/core.hpp"
#include <SDL2/SDL_render.h>

static auto& rnd = core::renderer;


void game::render_background()
{
    const int grid_size = 64;

    Point start { 0, 0 };

    auto screen = screen_size();

    Point count {
        (screen.x - start.x) / grid_size,
        (screen.y - start.y) / grid_size
    };


    SDL_SetRenderDrawColor(rnd, 0, 128, 0, 255);

    for(int i = 0; i <= count.x; ++i) {
        int x = start.x + i * grid_size;
            SDL_RenderDrawLine(rnd, x, 0, x, screen.y);
    }

    for(int i = 0; i <= count.y; ++i) {
        int y = start.y + i * grid_size;
        SDL_RenderDrawLine(rnd, 0, y, screen.x, y);
    }
}

