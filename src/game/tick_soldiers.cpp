#include "game/tick.hpp"
#include "game/timeline.hpp"
#include "game/soldier.hpp"
#include "game/do_overlap.hpp"
#include "core/scene.hpp"
#include <iostream>

using std::cout;
using std::endl;


void game::tick_soldiers(u32 ms)
{
    level_time += ms;
    if(level_time > duel_timeout) {
        queue_reset_timeline();
        cout << "Duel timeout" << endl;
    }

    for(auto& soldier : soldiers()) {
        soldier.move(ms);
        soldier.tick_action(ms);
    }

    if(!player().alive) {
        cout << "Respawn timeline reset" << endl;
        queue_reset_timeline();
    }

    auto& _soldiers = soldiers();


    auto alive_enemies = false;
    for(u8 i = 0; i < enemy_count; ++i)
        if(_soldiers[i].alive)
            alive_enemies = true;
            
    if(!alive_enemies && level_time > duel_time) {
        won_duel = true;
        queue_reset_timeline();
        return;
    }

    for(u8 e = 0; e < enemy_count; ++e)
    for(u32 i = enemy_count; i < _soldiers.size(); ++i) {
        if(do_overlap(_soldiers[e], _soldiers[i]))
            _soldiers[i].alive = false;
    }
}

