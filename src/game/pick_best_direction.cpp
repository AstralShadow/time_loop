#include "game/pick_direction.hpp"
#include "game/soldier.hpp"


FPoint game::pick_best_direction(Soldier& entity)
{
    auto dodge = pick_dodge_direction(entity);
    if(dodge.x != 0 || dodge.y != 0)
        return dodge;


    return {0, 0};
}

    // Movement policy
    // 0.95 - close range bullet dodge
    // 0.03 - approach enemy soldier
    // 0.02 - random movement
    //
    // Possibly use dead soldiers as shields
    //
