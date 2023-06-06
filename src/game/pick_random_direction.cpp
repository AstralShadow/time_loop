#include "game/pick_direction.hpp"
#include "game/soldier.hpp"
#include "utils/trandom.hpp"
#include <map>

using std::map;
namespace {
    struct RNGToken;
}


static map<u32, FPoint> cache;


FPoint game::pick_random_direction(Soldier& entity)
{
    if(level_time < 2000) // not instantly
        return {0, 0};

    u32 id = &entity - &soldiers()[0];

    if(cache.find(id) == cache.end()) {
        cache[id] = {
            randomf<RNGToken*>(),
            randomf<RNGToken*>()
        };
    }

    float xrate = randomf<RNGToken*>();
    float yrate = randomf<RNGToken*>();
    cache[id].x += xrate - 0.5;
    cache[id].y += yrate - 0.5;
    if(cache[id].x < -5)
        cache[id].x = -5;
    if(cache[id].y < -5)
        cache[id].y = -5;
    if(cache[id].x > 5)
        cache[id].x = 5;
    if(cache[id].y > 5)
        cache[id].y = 5;

    return cache[id];
}

