#include "game/pick_direction.hpp"
#include "game/soldier.hpp"


inline FPoint operator * (FPoint p, float n)
{
    return {p.x * n, p.y * n};
}

static void normalize_direction(FPoint& d)
{
    if(d.x == 0 && d.y == 0)
        return;
    float angle = std::atan2(d.y, d.x);
    d.x = std::cos(angle);
    d.y = std::sin(angle);
}



FPoint game::pick_best_direction(Soldier& entity)
{
    auto dodge = pick_dodge_direction(entity);
    auto attack = pick_battle_direction(entity);
    auto open = pick_open_direction(entity);
    auto random = pick_random_direction(entity);
    normalize_direction(dodge);
    normalize_direction(attack);
    normalize_direction(open);
    normalize_direction(random);

    auto motion = dodge * 1000
                + attack * 40
                + open * 20;

    //if(motion.x != 0 || motion.y != 0) {
    {
        auto random = pick_random_direction(entity);
        normalize_direction(random);
        motion = motion + random;
    }

    return motion;
}

    // Possible Movement policy
    // 0.50 - close range bullet dodge
    // 0.25 - approach/evade player
    // 0.15 - approach center (open position)
    // 0.06 - approach dead soldiers
    // 0.04 - random movement (impatience)
    //
    // Possibly use dead soldiers as shields
    //
