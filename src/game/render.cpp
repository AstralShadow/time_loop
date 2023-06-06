#include "game/game.hpp"
#include "game/render.hpp"


void game::render(scene_uid)
{
    SDL_SetRenderDrawColor(rnd, 0, 0, 0, 255);
    SDL_RenderClear(rnd);

    render_soldiers();

    SDL_RenderPresent(rnd);
}
