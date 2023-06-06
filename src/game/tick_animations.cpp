#include "game/tick.hpp"
#include "game/render.hpp"
#include "game/timeline.hpp"


void game::tick_animations(u32 ms)
{
    const auto reset_p = reset_screen_duration / 2;
    auto& reset_t = reset_screen_time;

    if(reset_t > reset_p && reset_t - ms <= reset_p)
        reset_timeline();

    reset_t -= ms;
}

