#include "game/game.hpp"
#include "game/tick.hpp"


void game::tick(u32 ms, scene_uid)
{
    tick_keyboard(ms);
    tick_soldiers(ms);
    tick_bullets(ms);
}

