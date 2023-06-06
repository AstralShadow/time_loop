#include "game/tick.hpp"
#include "game/soldier.hpp"
#include "game/pick_direction.hpp"


void game::tick_enemy_controller(u32)
{
    auto& _soldiers = soldiers();
    for(u8 i = 0; i < enemy_count; ++i) {
        auto& enemy = _soldiers[i];

        auto direction = pick_best_direction(enemy);
        enemy.set_motion(direction);
    }

    // TODO Possibly throw your knife
}

