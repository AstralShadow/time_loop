#include "game/pick_direction.hpp"
#include "game/soldier.hpp"
#include "utils/screen.hpp"


FPoint game::pick_open_direction(Soldier& entity)
{
    auto screen = screen_size();
    auto pos = entity.pos;

    FPoint delta {
        screen.x / 2 - pos.x,
        screen.y / 2 - pos.y
    };

    float plausability = center_position_plausability;
    Point edge {
        screen.x * plausability / 2,
        screen.y * plausability / 2
    };

    if(pos.x > edge.x)
    if(pos.y > edge.y)
    if(pos.x < screen.x - edge.x)
    if(pos.y < screen.y - edge.y)
        return {0, 0};

    return delta;
}

