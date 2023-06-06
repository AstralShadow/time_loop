#include "game/timeline.hpp"
#include "game/soldier.hpp"
#include "game/bullet.hpp"
#include "game/render.hpp"
#include "game/tick.hpp"


void game::reset_timeline()
{
    level_time = 0;

    auto& _soldiers = soldiers();
    int i = 0;

    FPoint spawn = enemy_spawn_point();
    for(auto& soldier : _soldiers) {
        soldier.alive = true;
        if(i++ < enemy_count) {
            soldier.pos = spawn;
            soldier.timeline.events.clear();
            soldier.timeline.end = 0;
            if(i % 2) {
                spawn.x -= 250;
                spawn.y += 250;
            } else {
                spawn.y -= 250;
            }
        } else {
            soldier.pos = spawn_point();
        }
    }

    // Store mouse button state
    auto fire_attack_state = player().fire_attack;
    if(player().ceased_fire)
        fire_attack_state = false;

    if(!won_duel) { // no double player spawn
        _soldiers.push_back
            ({spawn_point()}); // new player
        _soldiers.back().player_friendly = true;
    }
    bullets().clear(); // Clear bullets

    // Restore mouse button state
    player().fire_attack = fire_attack_state;
}


void game::queue_reset_timeline()
{
    queue_reset_screen();
}

