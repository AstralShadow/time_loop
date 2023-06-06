#include "game/timeline.hpp"
#include "game/soldier.hpp"


void game::reset_timeline()
{
    level_time = 0;

    auto& _soldiers = soldiers();
    for(auto& soldier : _soldiers)
        soldier.pos = {0, 0};

    _soldiers.emplace_back(); // new player
}

