#include "game/tick.hpp"
#include "game/render.hpp"
#include "game/timeline.hpp"
#include "game/soldier.hpp"

bool game::won_duel = false;


void game::tick_animations(u32 ms)
{
    const auto reset_p = reset_screen_duration / 2;
    auto& reset_t = reset_screen_time;

    if(reset_t > reset_p && reset_t - ms <= reset_p) {
        if(won_duel) {
            enemy_count++;
            soldiers().clear();
        }

        reset_timeline();

        if(enemy_count > max_enemy_count)
            core::set_scene("win");
    }

    reset_t -= ms;
    if(reset_t < 0)
        won_duel = false;
}

