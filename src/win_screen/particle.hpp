#ifndef INCLUDE_WS_PARTICLE_HPP
#define INCLUDE_WS_PARTICLE_HPP

#include "utils/types.hpp"
#include "utils/point.hpp"
#include <SDL2/SDL_pixels.h>
#include <vector>

using std::vector;


namespace win_screen
{
    struct Particle
    {
        FPoint pos;
        FPoint delta {0, 0};
        float size;
        SDL_Color color;
    };

    const u32 particle_max_count = 20000;
    vector<Particle>& particles();

    void spawn_particle();
    const u32 particle_spawn_delay = 1;
}

#endif // INCLUDE_WS_PARTICLE_HPP
