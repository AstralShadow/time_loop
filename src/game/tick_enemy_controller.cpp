#include "game/tick.hpp"
#include "game/soldier.hpp"


void game::tick_enemy_controller(u32 ms)
{
    auto& enemy = game::enemy();
    // Movement policy
    // 1 - close range bullet dodge
    // 2 - approach time shadow
    // 3 - random movement
    //
    // Possibly use dead soldiers as shields
    //
    // Possibly throw your knife
}

