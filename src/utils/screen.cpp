#include "utils/screen.hpp"
#include "core/core.hpp"
#include <SDL2/SDL_render.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
EM_JS(int, canvas_get_width, (), {
    return document.getElementById("canvas").offsetWidth;
});
EM_JS(int, canvas_get_height, (), {
    return document.getElementById("canvas").offsetHeight;
});
#else
static auto& rnd = core::renderer;
#endif

static Point _screen_size {0, 0};


Point screen_size()
{
    return _screen_size;
}


void update_screen_size()
{
    auto& screen = _screen_size;

#ifdef __EMSCRIPTEN__
    screen.x = canvas_get_width();
    screen.x = canvas_get_height();
    SDL_SetWindowSize(core::window, screen.x, screen.y);
#else
    SDL_GetRendererOutputSize(rnd, &screen.x, &screen.y);
#endif
}

