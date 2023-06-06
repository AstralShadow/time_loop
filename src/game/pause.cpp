#include "game/tick.hpp"

int game::paused_time = 0;

void game::pause(u32 ms)
{
    paused_time = ms;
}

