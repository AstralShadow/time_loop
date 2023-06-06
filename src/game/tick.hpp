#ifndef INCLUDE_GAME_TICK_HPP
#define INCLUDE_GAME_TICK_HPP

#include "utils/types.hpp"
#include "utils/point.hpp"


namespace game
{
    extern Point mouse;

    void tick_keyboard(u32 ms);
    void tick_mouse(u32 ms);

    void tick_soldiers(u32 ms);
    void tick_bullets(u32 ms);
}

#endif // INCLUDE_GAME_TICK_HPP
