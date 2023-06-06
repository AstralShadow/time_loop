#ifndef INCLUDE_WIN_SCREEN_WIN_SCREEN_HPP
#define INCLUDE_WIN_SCREEN_WIN_SCREEN_HPP

#include "utils/types.hpp"


namespace win_screen
{
    struct scene_uid_t;
    typedef struct scene_uid_t* scene_uid;

    void init(int, char**, scene_uid = 0);
    void deinit(scene_uid = 0);

    void tick(u32 ms, scene_uid = 0);
    void render(scene_uid = 0);
}

#endif // INCLUDE_WIN_SCREEN_WIN_SCREEN_HPP
