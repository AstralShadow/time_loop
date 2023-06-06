#ifndef INCLUDE_GAME_RENDER_HPP
#define INCLUDE_GAME_RENDER_HPP

#include "core/core.hpp"
#include <SDL2/SDL_render.h>

namespace game
{
    static auto& rnd = core::renderer;

    void render_background();

    void render_soldiers();
    void render_bullets();

    const int reset_screen_duration = 1500;
    extern int reset_screen_time; // 1500 -> 750 -> 0
    void queue_reset_screen();
    void render_reset_screen();

    void render_overlay_clock();
}

#endif // INCLUDE_GAME_RENDER_HPP
