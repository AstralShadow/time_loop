#include "game/game.hpp"
#include "game/tick.hpp"
#include "game/keyboard.hpp"
#include "core/core.hpp"
#include "game/soldier.hpp"
#include <SDL2/SDL_events.h>
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

Point game::mouse {0, 0};


void game::mouseup(SDL_MouseButtonEvent &,
                   scene_uid)
{
    player().stop_fire();
}

void game::mousedown(SDL_MouseButtonEvent &,
                     scene_uid)
{
    player().start_fire();
}

void game::mouse_motion(SDL_MouseMotionEvent& ev,
                        scene_uid)
{
    mouse.x = ev.x;
    mouse.y = ev.y;
}


void game::tick_mouse(u32)
{
    auto& _player = player();
    FPoint direction {
        mouse.x - _player.pos.x,
        mouse.y - _player.pos.y
    };

    float angle = std::atan2(direction.y, direction.x);
    _player.set_direction(angle);
}

