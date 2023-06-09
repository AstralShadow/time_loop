#include "game/soldier.hpp"
#include "game/bullet.hpp"
#include "utils/screen.hpp"
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using game::Soldier;

u8 game::enemy_count = 1;

FPoint& game::spawn_point()
{
    static FPoint _spawn_point {200, 200};
    return _spawn_point;
}

FPoint& game::enemy_spawn_point()
{
    static FPoint _spawn_point;
    _spawn_point = {
        static_cast<float>(screen_size().x - 200),
        static_cast<float>(screen_size().y - 200)
    };
    return _spawn_point;
}


vector<Soldier>& game::soldiers()
{
    static vector<Soldier> _soldiers;
    return _soldiers;
}

static void initial_soldier_spawn()
{
    auto& _soldiers = game::soldiers();

    FPoint spawn = game::enemy_spawn_point();
    for(u8 i = 0; i < game::enemy_count; ++i) {
        _soldiers.push_back({spawn});
        _soldiers.back().player_friendly = false;

        if(i % 2) {
            spawn.x -= 250;
            spawn.y += 250;
        } else {
            spawn.y -= 250;
        }
    }

    _soldiers.push_back({game::spawn_point()});
    _soldiers.back().player_friendly = true;
}

Soldier& game::player()
{
    auto& _soldiers = soldiers();
    if(_soldiers.size() < 2) {
        initial_soldier_spawn();
    }
    return _soldiers.back();
}

Soldier& game::enemy()
{
    auto& _soldiers = soldiers();
    if(_soldiers.size() < 2) {
        initial_soldier_spawn();
    }
    return _soldiers.front();
}


static void normalize_direction(FPoint& d)
{
    if(d.x == 0 && d.y == 0)
        return;
    float angle = std::atan2(d.y, d.x);
    d.x = std::cos(angle);
    d.y = std::sin(angle);
}


void Soldier::set_motion(FPoint direction)
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
    if(!alive)
        return;

    auto state = timeline.state();
    FPoint movement = state.movement;

    pos.x += movement.x * ms * speed() / 1000;
    pos.y += movement.y * ms * speed() / 1000;

    // Stay in screen
    auto screen = screen_size();
    if(pos.x - size() < 0)
        pos.x = size();
    if(pos.y - size() < 0)
        pos.y = size();
    if(pos.x + size() > screen.x)
        pos.x = screen.x - size();
    if(pos.y + size() > screen.y)
        pos.y = screen.y - size();
}


void Soldier::set_direction(float _direction)
{
    direction = _direction;
}

void Soldier::start_fire()
{
    fire_attack = true;
    ceased_fire = false;
    update_timeline();
}

void Soldier::stop_fire()
{
    ceased_fire = true;
}


void Soldier::tick_action(u32)
{
    if(!alive)
        return;

    if(timeline.end < level_time)
        update_timeline();
    else
        load_timeline();
    
    u32 cooldown_time = level_time - last_fire;
    bool can_fire = cooldown_time > fire_delay();

    if(cooldown_time > 50 && ceased_fire) {
        ceased_fire = false;
        fire_attack = false;
    }

    if(fire_attack && can_fire) {
        Bullet bullet {
            this->pos,
            FPoint {
                cos(this->direction),
                sin(this->direction)
            }
        };
        auto _dist = this->size() + bullet.size() + 2;
        bullet.pos.x += _dist * bullet.direction.x;
        bullet.pos.y += _dist * bullet.direction.y;
        bullet.player_friendly = player_friendly;
        bullets().push_back(bullet);
        last_fire = level_time;
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
    if(abs(state.direction - direction) > 0.01) {
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



