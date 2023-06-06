#include "core/scene.hpp"

#include "game/game.hpp"
#include "win_screen/win_screen.hpp"


void core::register_scenes()
{
    core::scene<game::scene_uid>("game");
    core::set_scene("game");

    core::scene<win_screen::scene_uid>("win");
    //core::set_scene("win");
}


