#include "game/game.hpp"
#include "game/tick.hpp"


void game::tick(u32 ms, scene_uid)
{
    tick_animations(ms);

    if(paused_time > 0) {
        paused_time -= ms;
        return;
    }

    tick_keyboard(ms);
    tick_mouse(ms);

    tick_soldiers(ms);
    tick_bullets(ms);
    tick_enemy_controller(ms);
}

