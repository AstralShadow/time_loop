#include "game/tick.hpp"
#include "game/timeline.hpp"
#include "game/soldier.hpp"


void game::tick_soldiers(u32 ms)
{
    level_time += ms;
    for(auto& soldier : soldiers()) {
        soldier.move(ms);
        soldier.tick_action(ms);
    }
}

