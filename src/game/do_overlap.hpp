#ifndef INCLUDE_GAME_DO_OVERLAP_HPP
#define INCLUDE_GAME_DO_OVERLAP_HPP

#include "utils/point.hpp"

namespace game
{

    template<class T1, class T2> static
    bool do_overlap(T1 const& a, T2 const& b)
    {
        FPoint delta {
            a.pos.x - b.pos.x,
            a.pos.y - b.pos.y
        };

        float distance2 = delta.x * delta.x 
                         + delta.y * delta.y;

        float min_dist = a.size() + b.size();
        if(distance2 < min_dist * min_dist)
            return true;
        return false;
    }

}

#endif // INCLUDE_GAME_DO_OVERLAP_HPP
