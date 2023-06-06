#ifndef INCLUDE_GAME_SOLDIER_HPP
#define INCLUDE_GAME_SOLDIER_HPP

#include "utils/point.hpp"
#include "utils/types.hpp"
#include "game/timeline.hpp"
#include <vector>

using std::vector;


namespace game
{
    struct Soldier
    {
        FPoint pos;
        float direction = 0;
        bool alive = true;
        bool fire_attack = false;
        bool player_friendly = false;
        u32 last_fire = 0;

        // Serves to provide 50ms bonus to every fire action that stays under 50ms
        bool ceased_fire = false;

        int size() const { return 20; } // radius
        int speed() const { return 400; } // px/s
        u32 fire_delay() const { return 450; } // ms

        Timeline timeline {};

        void set_motion(FPoint direction);
        void set_direction(float direction);
        void start_fire();
        void stop_fire();

        void move(u32 ms);
        void tick_action(u32 ms);

    private:
        void update_timeline();
        void load_timeline();
    };

    vector<Soldier>& soldiers();
    Soldier& player();
    Soldier& enemy();

    FPoint& spawn_point();
    FPoint& enemy_spawn_point();

    const u8 max_enemy_count = 4; // hard coded in enemy positioning
    extern u8 enemy_count;
}

#endif // INCLUDE_GAME_SOLDIER_HPP
