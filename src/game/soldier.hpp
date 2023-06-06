#ifndef INCLUDE_GAME_SOLDIER_HPP
#define INCLUDE_GAME_SOLDIER_HPP

#include "utils/point.hpp"
#include <vector>

using std::vector;


namespace game
{
    struct Soldier
    {
        Point pos;
        int size() { return 32; }
        int speed() { return 500; } // px/s

        void move(Point direction);
    };

    vector<Soldier>& soldiers();
    Soldier& player();
}

#endif // INCLUDE_GAME_SOLDIER_HPP
