#include "win_screen/path.hpp"
#include <cmath>


float win_screen::get_path_length()
{
    static float length = [](){
        float dist = 0;

        FPoint last {path[0], path[1]};
        for(u32 i = 2; i < path.size() - 1; i+=2) {
            FPoint current {path[i], path[i + 1]};
            float dx = current.x - last.x;
            float dy = current.y - last.y;
            dist += sqrt(dx * dx + dy * dy);
            last = current;
        }

        return dist;
    }();

    return length;
}


SDL_FRect win_screen::get_path_area()
{
    static SDL_FRect area = [](){
        SDL_FRect area {
            path[0], path[1],
            path[0], path[1]
        };

        for(u32 i = 2; i < path.size() - 1; i+=2) {
            FPoint current {path[i], path[i + 1]};
            if(area.x > current.x)
                area.x = current.x;
            if(area.y > current.y)
                area.y = current.y;
            if(area.w < current.x)
                area.w = current.x;
            if(area.h < current.y)
                area.h = current.y;
        }

        area.w -= area.x;
        area.h -= area.y;
        return area;
    }();

    return area;
}


FPoint win_screen::get_path_pos_at(float k)
{
    float target = k * get_path_length();
    float dist = 0;

    FPoint last {path[0], path[1]};
    for(u32 i = 2; i < path.size() - 1; i+=2) {
        FPoint current {path[i], path[i + 1]};
        float dx = current.x - last.x;
        float dy = current.y - last.y;
        float d = sqrt(dx * dx + dy * dy);
        if(dist + d > target) {
            float extra= dist - target;
            float angle = atan2(dy, dx);
            current.x += cos(angle) * extra;
            current.y += sin(angle) * extra;
            return current;
        }
        dist += d;
        last = current;
    }

    return {0, 0};
}


