#include "game/pick_direction.hpp"
#include "game/soldier.hpp"


FPoint game::pick_best_direction(Soldier& entity)
{
    auto dodge = pick_dodge_direction(entity);
    if(dodge.x != 0 || dodge.y != 0)
        return dodge;

    auto open = pick_open_direction(entity);
    if(open.x != 0 || open.y != 0)
        return open;

    return {0, 0};
}

    // Movement policy
    // 0.75 - close range bullet dodge
    // 0.15 - approach center (open position)
    // 0.06 - approach enemy soldier 
    // 0.04 - random movement
    //
    // Possibly use dead soldiers as shields
    //
