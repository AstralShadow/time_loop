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
        _soldiers.push_back({spawn_point()});
    return _soldiers.back();
}

FPoint& game::spawn_point()
{
    static FPoint _spawn_point {200, 200};
    return _spawn_point;
}


static void normalize_direction(FPoint& d)
{
    if(d.x == 0 && d.y == 0)
        return;
    float angle = std::atan2(d.y, d.x);
    d.x = std::cos(angle);
    d.y = std::sin(angle);
}


void Soldier::kb_move(FPoint direction)
{
    normalize_direction(direction);

    auto last = timeline.state();
    if(last.movement == direction)
        return;

    Event event = timeline.state();
    event.time = level_time;
    event.movement = direction;
    timeline.add_event(event);
}

void Soldier::move(u32 ms)
{
    auto state = timeline.state();
    FPoint movement = state.movement;

    pos.x += movement.x * ms * speed() / 1000;
    pos.y += movement.y * ms * speed() / 1000;
}


void Soldier::set_direction(float _direction)
{
    direction = _direction;
}

void Soldier::start_fire()
{
    fire_attack = true;
}

void Soldier::stop_fire()
{
    fire_attack = false;
}


void Soldier::tick_action(u32 ms)
{
    if(!alive)
        return;

    if(timeline.end < level_time)
        update_timeline();
    else
        load_timeline();

    if(fire_attack) {
        
    }
}

void Soldier::update_timeline()
{
    auto state = timeline.state();
    bool updated = false;

    if(state.fire_attack != fire_attack) {
        state.fire_attack = fire_attack;
        updated = true;
    }

    if(fire_attack) // Decrease memory footprint
    if(std::abs(state.direction - direction) > 0.01) {
        state.direction = direction;
        updated = true;
    }

    if(updated) {
        state.time = level_time;
        timeline.add_event(state);
    }
}

void Soldier::load_timeline()
{
    auto state = timeline.state();
    direction = state.direction;
    fire_attack = state.fire_attack;
}


