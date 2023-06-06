#include "win_screen/win_screen.hpp"
#include "win_screen/render.hpp"
#include "utils/screen.hpp"
#include <SDL2/SDL_timer.h>


void win_screen::render(scene_uid)
{
    update_screen_size();

    static u32 start = SDL_GetTicks();
    int green = 200 - (SDL_GetTicks() - start) / 10;
    if(green < 128)
        green = 128;

    SDL_SetRenderDrawColor(rnd, 0, green, 0, 255);
    SDL_RenderClear(rnd);

    render_particles();

    SDL_RenderPresent(rnd);
}
