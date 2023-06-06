#ifndef INCLUDE_GAME_PICK_DIRECTION_HPP
#define INCLUDE_GAME_PICK_DIRECTION_HPP

#include "utils/point.hpp"

namespace game
{
    struct Soldier;
    FPoint pick_best_direction(Soldier&);
    FPoint pick_dodge_direction(Soldier&);

    // Calculated 49 as sufficient
    const int dodge_area = 57; // radius, px
}

#endif // INCLUDE_GAME_PICK_DIRECTION_HPP
