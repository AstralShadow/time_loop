#ifndef INCLUDE_GAME_SOLDIER_HPP
#define INCLUDE_GAME_SOLDIER_HPP

#include "utils/point.hpp"
#include "utils/types.hpp"
#include "game/timeline.hpp"
#include <vector>

using std::vector;


namespace game
{
    struct Soldier
    {
        FPoint pos;
        int size() { return 20; } // radius
        int speed() { return 500; } // px/s

        Timeline timeline {};

        void kb_move(FPoint direction);

        void move(u32 ms);
    };

    vector<Soldier>& soldiers();
    Soldier& player();

    FPoint& spawn_point();
}

#endif // INCLUDE_GAME_SOLDIER_HPP
