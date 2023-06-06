#include "game/game.hpp"
#include "game/keyboard.hpp"
#include "core/core.hpp"
#include "game/timeline.hpp"
#include "game/soldier.hpp"
#include <SDL2/SDL_events.h>
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;


void game::keydown(SDL_KeyboardEvent& ev, scene_uid)
{
    auto const& scancode = ev.keysym.scancode;
    if(scancode == SDL_SCANCODE_Q)
        core::stop();

    for(auto code : keys_action) {
        if(scancode == code) {
            reset_timeline();
            cout << "Resetting timeline" << endl;
        }
    }
}


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
    auto& _player = player();
    FPoint direction {
        ev.x - _player.pos.x,
        ev.y - _player.pos.y
    };

    float angle = std::atan2(direction.y, direction.x);
    _player.set_direction(angle);
}

