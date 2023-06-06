#include "win_screen/win_screen.hpp"
#include "win_screen/particle.hpp"
#include "utils/trandom.hpp"


void win_screen::tick(u32 ms, scene_uid)
{
    static u32 sum = 0;
    sum += ms;

    if(particles().size() < particle_max_count)
    while(sum > particle_spawn_delay) {
        sum -= particle_spawn_delay;
        spawn_particle();
    }


    struct RNGToken;
    float spread = 20;
    for(auto& p : particles()) {
        p.delta.x += randomf<RNGToken*>() - 0.5;
        p.delta.y += randomf<RNGToken*>() - 0.5;
        p.size += randomf<RNGToken*>() * 0.08f;
        if(p.size > 20)
            p.size = 5;

        if(p.delta.x < -spread)
            p.delta.x = -spread;
        if(p.delta.y < -spread)
            p.delta.y = -spread;
        if(p.delta.x > spread)
            p.delta.x = spread;
        if(p.delta.y > spread)
            p.delta.y = spread;
    }
}


