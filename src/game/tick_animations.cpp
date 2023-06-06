#include "game/tick.hpp"
#include "game/render.hpp"
#include "game/timeline.hpp"


void game::tick_animations(u32 ms)
{
    if(reset_screen_time > 0 && reset_screen_time <= ms)
        reset_timeline();
    reset_screen_time -= ms;

}

