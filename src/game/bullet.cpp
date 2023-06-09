#include "game/bullet.hpp"

using game::Bullet;


vector<Bullet>& game::bullets()
{
    static vector<Bullet> _bullets;
    return _bullets;
}


void Bullet::move(u32 ms)
{
    pos.x += direction.x * speed() * ms / 1000;
    pos.y += direction.y * speed() * ms / 1000;
}

