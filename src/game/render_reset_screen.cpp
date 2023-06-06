#include "game/render.hpp"
#include "utils/screen.hpp"


void game::render_reset_screen()
{
    if(reset_screen_time <= 0)
        return;

    auto screen = screen_size();

    SDL_Rect area {
        0,
        0,
        screen.x,
        screen.y
    };

    float progress = 2.0f * reset_screen_time
                      / reset_screen_duration - 1;

    area.x = area.w;
    for(int i = 0; i < 3; i++)
        area.x *= progress;

    SDL_SetRenderDrawColor(rnd, 230, 200, 0, 255);
    SDL_RenderFillRect(rnd, &area);
}

