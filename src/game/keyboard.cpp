#include "game/keyboard.hpp"
#include "game/soldier.hpp"
#include <utility>


void game::tick_keyboard(u32 ms)
{
    const u8* kb_state = SDL_GetKeyboardState(nullptr);

    auto& player = game::player();

    Point direction {0, 0};


    struct KeyListData
    {
        const u8* keys;
        u8 count;
        Point action;
    };

    KeyListData keys_data[] {
        {&keys_left[0], sizeof(keys_left), {-1, 0}},
        {&keys_right[0], sizeof(keys_right), {1, 0}},
        {&keys_up[0], sizeof(keys_up), {0, -1}},
        {&keys_down[0], sizeof(keys_down), {0, 1}}
    };

    for(auto data : keys_data) {
        for(int i = 0; i < data.count; ++i) {
            u8 key = data.keys[i];
            if(!kb_state[key])
                continue;

            direction.x += data.action.x;
            direction.y += data.action.y;
        }
    }

    player.move(direction);
}

