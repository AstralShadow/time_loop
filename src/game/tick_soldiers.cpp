#include "game/tick.hpp"
#include "game/timeline.hpp"
#include "game/soldier.hpp"
#include "game/do_overlap.hpp"


void game::tick_soldiers(u32 ms)
{
    level_time += ms;
    for(auto& soldier : soldiers()) {
        soldier.move(ms);
        soldier.tick_action(ms);
    }

    if(!player().alive)
        queue_reset_timeline();

    auto _enemy = enemy();
    if(_enemy.alive == false) {
        // TODO win screen
        return;
    }

    auto& _soldiers = soldiers();
    for(int i = 1; i < _soldiers.size(); ++i) {
        if(do_overlap(_enemy, _soldiers[i]))
            _soldiers[i].alive = false;
    }
}

