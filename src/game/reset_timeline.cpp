#include "game/timeline.hpp"
#include "game/soldier.hpp"
#include "game/bullet.hpp"
#include "game/render.hpp"


void game::reset_timeline()
{
    level_time = 0;

    auto& _soldiers = soldiers();
    for(auto& soldier : _soldiers) {
        soldier.alive = true;
        soldier.pos = spawn_point();
    }

    // Store mouse button state
    auto fire_attack_state = player().fire_attack;
    if(player().ceased_fire)
        fire_attack_state = false;

    enemy().pos = enemy_spawn_point();
    enemy().timeline.events.clear();
    enemy().timeline.end = 0;

    _soldiers.push_back({spawn_point()}); // New player
    _soldiers.back().player_friendly = true;
    bullets().clear(); // Clear bullets

    // Restore mouse button state
    player().fire_attack = fire_attack_state;
}


void game::queue_reset_timeline()
{
    queue_reset_screen();
}

