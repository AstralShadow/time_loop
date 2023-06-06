#include "game/tick.hpp"
#include "game/bullet.hpp"


void game::tick_bullets(u32 ms)
{
    for(auto& bullet : bullets()) {
        bullet.move(ms);
    }
}

