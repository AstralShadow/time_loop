#include "game/tick.hpp"
#include "game/render.hpp"

int game::reset_screen_time = 0;

void game::queue_reset_screen()
{
    pause(reset_screen_duration);
    reset_screen_time = reset_screen_duration;
}

