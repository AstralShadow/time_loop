#include "game/soldier.hpp"
#include <iostream>

using std::cout;
using std::endl;
using game::Soldier;


vector<Soldier>& game::soldiers()
{
    static vector<Soldier> _soldiers;
    return _soldiers;
}

Soldier& game::player()
{
    return soldiers()[0];
}



Soldier::move(Point direction)
{
    if(direction.x == 0 && direction.y == 0)
        return;

}

