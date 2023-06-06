#include "game/pick_direction.hpp"
#include "game/soldier.hpp"
#include <cmath>
#include <iostream>

using std::cout;
using std::endl;


FPoint game::
pick_battle_direction(Soldier& entity)
{
    Soldier* _target = nullptr;
    float _distance = 0;

    for(auto& target : soldiers()) {
        if(&target == &entity)
            continue;

        if(!target.alive)
            continue;

        FPoint delta {
            entity.pos.x - target.pos.x,
            entity.pos.y - target.pos.y
        };
        float distance = delta.x * delta.x
                          + delta.y * delta.y;

        if(!_target) {
            _target = &target;
            _distance = distance;
            continue;
        }

        if(distance < _distance) {
            _target = &target;
            _distance = distance;
        }
    }

    if(_target)
        return pick_battle_direction(entity, *_target);

    return {0, 0};
}


FPoint game::
pick_battle_direction(Soldier& entity, Soldier& target)
{
    auto pos = entity.pos;

    FPoint direction;

    auto cooldown_t = level_time - target.last_fire;
    int reaction_t = target.fire_delay() - cooldown_t;

    FPoint delta {
        target.pos.x - entity.pos.x,
        target.pos.y - entity.pos.y
    };
    float distance = sqrt(delta.x * delta.x
                           + delta.y * delta.y);

    // median human reaction time is 273ms
    int human_delay = 220;
    if(reaction_t < human_delay && !target.fire_attack)
        reaction_t = human_delay;

    // Sharp attacks
    float reach_t = 1000 * distance / entity.speed();
    if(level_time > 1000)
        if(reach_t < reaction_t)
            return delta;

    // Keep distance
    if(distance < save_defense_distance)
        return {-delta.x, -delta.y};
    else if(distance > minimal_attack_distance)
        if(level_time > 1000) // not instantly
            return delta;


    return {0, 0};
}


