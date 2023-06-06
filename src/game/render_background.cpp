#include "game/render.hpp"
#include "utils/screen.hpp"
#include "core/core.hpp"
#include <SDL2/SDL_render.h>
#include <iostream>

using std::cout;
using std::endl;

static auto& rnd = core::renderer;


inline void set_main_color()
{
    SDL_SetRenderDrawColor(rnd, 0, 128, 0, 255);
}

inline void set_base_color()
{
    SDL_SetRenderDrawColor(rnd, 255, 0, 0, 255);
}


namespace game 
{
void render_background()
{
    const int grid_size = 64;

    Point start { 0, 0 };

    auto screen = screen_size();

    Point count {
        (screen.x - start.x) / grid_size,
        (screen.y - start.y) / grid_size
    };


    set_main_color();

    for(int i = 0; i <= count.x; ++i) {
        int x = start.x + i * grid_size;
        if(i == 1) {
            set_base_color();
            SDL_RenderDrawLine(rnd, x, 0, x, screen.y);
            set_main_color();
        } else  {
            SDL_RenderDrawLine(rnd, x, 0, x, screen.y);
        }
    }

    for(int i = 0; i <= count.y; ++i) {
        int y = start.y + i * grid_size;
        if(i == 1) {
            set_base_color();
            SDL_RenderDrawLine(rnd, 0, y, screen.x, y);
            set_main_color();
        } else  {
            SDL_RenderDrawLine(rnd, 0, y, screen.x, y);
        }
    }
}

}
