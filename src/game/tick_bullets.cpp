#include "game/tick.hpp"
#include "game/bullet.hpp"
#include "game/soldier.hpp"
#include "game/do_overlap.hpp"

// Can soldiers harm allies
const bool friendlyfire = false;

void game::tick_bullets(u32 ms)
{
    auto& _bullets = bullets();
    for(auto& bullet : _bullets) {
        bullet.move(ms);
    }

    auto b_itr = _bullets.begin();
    while(b_itr != _bullets.end()) {
        
        for(auto& soldier : soldiers()) {
            if(!friendlyfire) {
                bool friendly = soldier.player_friendly
                              == b_itr->player_friendly;
                if(friendly)
                    continue;
            }

            if(do_overlap(soldier, *b_itr)) {
                soldier.alive = false;
                b_itr = _bullets.erase(b_itr);
                goto next_bullet;
            }
        }

        b_itr++;
        next_bullet:;
    }
}

