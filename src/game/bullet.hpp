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
        int size() { return 8; }
        FPoint direction;

        void move(u32 ms);
    };

    vector<Bullet>& bullets();
}

#endif // INCLUDE_GAME_BULLET_HPP
