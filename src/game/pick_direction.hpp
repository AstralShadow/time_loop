#ifndef INCLUDE_GAME_PICK_DIRECTION_HPP
#define INCLUDE_GAME_PICK_DIRECTION_HPP

#include "utils/point.hpp"

namespace game
{
    struct Soldier;

    FPoint pick_best_direction(Soldier&);


    // Attempt to dodge closest bullet
    FPoint pick_dodge_direction(Soldier&);

    // Calculated 49 as sufficient
    const int dodge_area = 60; // radius, px


    // Approach the middle of the screen
    FPoint pick_open_direction(Soldier&);
    // How closely to stick to the screen center
    const float center_position_plausability = 0.3;

    FPoint pick_battle_direction(Soldier&);
    FPoint pick_battle_direction(Soldier&,
                                 Soldier& target);
    // Calculated 85 as sufficient
    const int save_defense_distance = 93; // px
    // Strieve to be closer to attack faster;
    const int minimal_attack_distance = 145; // px

    // Just wander around
    FPoint pick_random_direction(Soldier&);
}

#endif // INCLUDE_GAME_PICK_DIRECTION_HPP
