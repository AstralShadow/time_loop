#ifndef INCLUDE_GAME_TICK_HPP
#define INCLUDE_GAME_TICK_HPP

#include "utils/types.hpp"


namespace game
{
    void tick_keyboard(u32 ms);
    void tick_soldiers(u32 ms);
    void tick_bullets(u32 ms);
}

#endif // INCLUDE_GAME_TICK_HPP
