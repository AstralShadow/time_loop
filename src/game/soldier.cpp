#include "game/soldier.hpp"
#include <iostream>
#include <cmath>

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
    auto& _soldiers = soldiers();
    if(_soldiers.size() == 0)
        _soldiers.emplace_back();
    return _soldiers.back();
}


static void normalize_direction(FPoint& d)
{
    if(d.x == 0 && d.y == 0)
        return;
    float angle = atan2(d.y, d.x);
    d.x = cos(angle);
    d.y = sin(angle);
}


void Soldier::kb_move(FPoint direction)
{
    normalize_direction(direction);

    auto last = timeline.state();
    if(last.direction == direction)
        return;

    Event event = timeline.state();
    event.time = level_time;
    event.direction = direction;
    timeline.add_event(event);
}

void Soldier::move(u32 ms)
{
    auto state = timeline.state();
    FPoint direction = state.direction;

    pos.x += direction.x * ms * speed() / 1000;
    pos.y += direction.y * ms * speed() / 1000;
}

