#ifndef INCLUDE_GAME_BULLET_HPP
#define INCLUDE_GAME_BULLET_HPP

#include "utils/types.hpp"
#include "utils/point.hpp"
#include <vector>

using std::vector;


namespace game
{
    struct Bullet
    {
        FPoint pos;
        FPoint direction;
        bool player_friendly = false;

        int size() const { return 8; } // radius
        int speed() const { return 1000; } // px/s

        void move(u32 ms);
    };

    vector<Bullet>& bullets();
}

#endif // INCLUDE_GAME_BULLET_HPP
