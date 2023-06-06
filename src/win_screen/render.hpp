#ifndef INCLUDE_WIN_SCREEN_RENDER_HPP
#define INCLUDE_WIN_SCREEN_RENDER_HPP

#include "core/core.hpp"
#include <SDL2/SDL_render.h>

namespace win_screen
{
    static auto& rnd = core::renderer;

    void render_particles();
}

#endif // INCLUDE_WIN_SCREEN_RENDER_HPP
