#include "game/game.hpp"
#include "game/keyboard.hpp"
#include "core/core.hpp"
#include "game/timeline.hpp"
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

