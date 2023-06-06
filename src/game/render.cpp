#include "game/game.hpp"
#include "game/render.hpp"
#include "utils/screen.hpp"


void game::render(scene_uid)
{
    update_screen_size();

    SDL_SetRenderDrawColor(rnd, 0, 0, 0, 255);
    SDL_RenderClear(rnd);

    //render_background();

    render_soldiers();
    render_bullets();

    render_reset_screen();

    SDL_RenderPresent(rnd);
}
