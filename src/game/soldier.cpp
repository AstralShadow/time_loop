#include "game/soldier.hpp"
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using game::Soldier;


vector<Soldier>& game::soldiers()
{
    static vector<Soldier> _soldiers {{{0, 0}}};
    return _soldiers;
}

Soldier& game::player()
{
    return soldiers()[0];
}


static void normalize_direction(FPoint& d)
{
    float angle = atan2(d.y, d.x);
    d.x = cos(angle);
    d.y = sin(angle);
}


void Soldier::move(FPoint direction, u32 time)
{
    if(direction.x == 0 && direction.y == 0)
        return;

    normalize_direction(direction);

    pos.x += direction.x * time * speed() / 1000;
    pos.y += direction.y * time * speed() / 1000;
}

