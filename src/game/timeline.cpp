#include "game/timeline.hpp"

using game::Event;
using game::Timeline;

u32 game::level_time;


Event::Event() :
    time(level_time)
{ }


Event Timeline::state()
{
    if(events.size() == 0)
        return {};

    if(end < level_time)
        return events.back();

    if(events.front().time > level_time)
        return {};

    Event last = events.front();
    for(u32 i = 1; i < events.size(); ++i) {
        if(events[i].time > level_time)
            break;
        last = events[i];
    }

    return last;
}


