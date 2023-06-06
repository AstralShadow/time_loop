#include "win_screen/particle.hpp"
#include "win_screen/path.hpp"
#include "utils/trandom.hpp"
#include "utils/screen.hpp"

using win_screen::Particle;


vector<Particle>& win_screen::particles()
{
    static vector<Particle> _particles;
    return _particles;
}


void win_screen::spawn_particle()
{
    struct RNGToken;

    float k = randomf<RNGToken*>();
    Particle particle {
        get_path_pos_at(k),
        {0, 0},
        1 + randomf<RNGToken*>() * 3,
        {
            0,
            static_cast<u8>(
                static_cast<int>
                    (randomf<RNGToken*>() * 195)
                + 64),
            static_cast<u8>(
                static_cast<int>
                    (randomf<RNGToken*>() * 195)
                + 64),
            255
        }
    };

    auto area = get_path_area();
    auto screen = screen_size();

    SDL_FRect targets[2] {
        {
            screen.x * 9 / 32.0f, screen.y / 2.0f,
            screen.x / 3.3f, 0
        },
        {
            screen.x * 23 / 32.0f, screen.y / 2.0f,
            screen.x / 3.3f, 0
        }
    };
    SDL_FRect* target = &targets[particles().size() % 2];
    target->h = target->w * area.h / area.w;
    target->x -= target->w / 2;
    target->y -= target->h / 2;

    particle.pos.x -= area.x;
    particle.pos.y -= area.y;
    particle.pos.x *= target->w / area.w;
    particle.pos.y *= target->h / area.h;
    particle.pos.x += target->x;
    particle.pos.y += target->y;

    particles().push_back(particle);
}

