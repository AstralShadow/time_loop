#include "win_screen/render.hpp"
#include "win_screen/particle.hpp"


void win_screen::render_particles()
{
    for(auto const& p : particles()) {
        SDL_SetRenderDrawColor(rnd,
            p.color.r, p.color.g,
            p.color.b, p.color.a);

        SDL_Rect area {
            static_cast<int>(p.pos.x + p.delta.x),
            static_cast<int>(p.pos.y + p.delta.y),
            static_cast<int>(p.size),
            static_cast<int>(p.size)
        };

        SDL_RenderFillRect(rnd, &area);
    }
}

