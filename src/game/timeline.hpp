#ifndef INCLUDE_GAME_TIME_HPP
#define INCLUDE_GAME_TIME_HPP

#include "utils/types.hpp"
#include "utils/point.hpp"
#include <vector>

using std::vector;


namespace game
{
    struct Event 
    {
        Event();
        ~Event() = default;

        u32 time;
        FPoint movement {0, 0};
        bool fire_attack = false;
        float direction = 0;
    };

    struct Timeline
    {
        u32 end = 0;
        vector<Event> events;

        Event state();

        void add_event(Event ev)
        {
            events.push_back(ev);
            if(end < ev.time)
                end = ev.time;
        }
    };


    extern u32 level_time;

    void queue_reset_timeline();
    void reset_timeline();
}

#endif // INCLUDE_GAME_TIME_HPP
