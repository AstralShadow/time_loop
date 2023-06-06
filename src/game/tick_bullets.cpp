#include "game/tick.hpp"
#include "game/bullet.hpp"
#include "game/soldier.hpp"
#include "game/do_overlap.hpp"
#include "utils/screen.hpp"

// Can soldiers harm allies
const bool friendlyfire = true;

// Wrap on screen
const bool wrap_on_screen = true;

void game::tick_bullets(u32 ms)
{
    auto& _bullets = bullets();
    for(auto& bullet : _bullets) {
        bullet.move(ms);
    }


    auto screen = screen_size();

    auto b_itr = _bullets.begin();
    while(b_itr != _bullets.end()) {

        auto& pos = b_itr->pos;
        if(wrap_on_screen) {
            if(pos.x < 0)
                pos.x += screen.x;
            if(pos.y < 0)
                pos.y += screen.y;
            if(pos.x > screen.x)
                pos.x -= screen.x;
            if(pos.y > screen.y)
                pos.y -= screen.y;
        } else {
            if(pos.x < 0 || pos.y < 0
               || pos.x > screen.x || pos.y > screen.y)
            {
                    b_itr = _bullets.erase(b_itr);
                    goto next_bullet;
            }
        }


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

