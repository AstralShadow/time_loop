#include "game/pick_direction.hpp"
#include "game/soldier.hpp"
#include "game/bullet.hpp"
#include "game/do_overlap.hpp"


FPoint game::pick_dodge_direction(Soldier& entity)
{
    struct {
        FPoint pos;
        int size() const { return dodge_area; }
    } entity_area {
        entity.pos,
    };

    vector<Bullet> near_bullets;
    for(auto bullet : bullets()) {
        if(do_overlap(bullet, entity_area))
            near_bullets.push_back(bullet);
    }
    if(near_bullets.size() == 0)
        return {0, 0};


    struct DodgeMotion
    {
        FPoint direction;
        float priority = 1;
    };


    vector<DodgeMotion> motions;

    auto pos = entity.pos;
    for(auto bullet : near_bullets) {
        // Well, this solution may be a bit crude,
        //  but there's charm hidden within inaccuracity
        float dx = bullet.pos.x - pos.x;
        float dy = bullet.pos.y - pos.y;
        float distance = dx * dx + dy * dy;

        DodgeMotion response {
            {-bullet.direction.y,
             bullet.direction.x}, // Move to the side
            distance
        };
        FPoint next_pos {
            pos.x + response.direction.x,
            pos.y + response.direction.y
        };
        dx = bullet.pos.x - next_pos.x;
        dy = bullet.pos.y - next_pos.y;
        distance = dx * dx + dy * dy;
        if(distance < response.priority) {
            // Not that side, the other one
            response.direction.x *= -1;
            response.direction.y *= -1;
        }

        motions.push_back(response);
    }

    float priority_sum = 0;
    for(auto motion : motions)
        priority_sum += motion.priority;

    FPoint final_motion {0, 0};
    for(auto motion : motions) {
        float p = motion.priority / priority_sum;
        final_motion.x += motion.direction.x * p;
        final_motion.y += motion.direction.y * p;
    }

    return final_motion;
}

