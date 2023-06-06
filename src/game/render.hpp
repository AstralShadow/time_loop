#ifndef INCLUDE_GAME_RENDER_HPP
#define INCLUDE_GAME_RENDER_HPP

#include "core/core.hpp"
#include <SDL2/SDL_render.h>

namespace game
{
    static auto& rnd = core::renderer;

    void render_soldiers();
}

#endif // INCLUDE_GAME_RENDER_HPP
