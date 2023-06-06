#include "game/timeline.hpp"
#include "game/soldier.hpp"
#include "game/bullet.hpp"


void game::reset_timeline()
{
    level_time = 0;

    auto& _soldiers = soldiers();
    for(auto& soldier : _soldiers)
        soldier.pos = spawn_point();

    _soldiers.push_back({spawn_point()}); // new player
    bullets().clear();
}

