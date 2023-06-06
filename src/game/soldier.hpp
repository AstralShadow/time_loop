#ifndef INCLUDE_GAME_SOLDIER_HPP
#define INCLUDE_GAME_SOLDIER_HPP

#include "utils/point.hpp"
#include "utils/types.hpp"
#include <vector>

using std::vector;


namespace game
{
    struct Soldier
    {
        FPoint pos;
        int size() { return 24; } // radius
        int speed() { return 500; } // px/s

        void move(FPoint direction, u32 time);
    };

    vector<Soldier>& soldiers();
    Soldier& player();
}

#endif // INCLUDE_GAME_SOLDIER_HPP
