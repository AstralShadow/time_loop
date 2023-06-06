#include "core/init.hpp"
#include "core/core.hpp"
#include "game/game.hpp"
#include "core/config.hpp"
#include <stdexcept>
#include <string>
#include <SDL2/SDL.h>
#ifdef USE_SDL2_NET
    #include <SDL2/SDL_net.h>
#endif
#ifdef USE_SDL2_IMAGE
    #include <SDL2/SDL_image.h>
#endif
#ifdef USE_SDL2_TTF
    #include <SDL2/SDL_ttf.h>
#endif

#ifndef WINDOW_WIDTH
    #define WINDOW_WIDTH 800
    #pragma message "WINDOW_WIDTH not defined. Default: " #WINDOW_WIDTH
#endif
#ifndef WINDOW_HEIGHT
    #define WINDOW_HEIGHT 600
    #pragma print WINDOW_HEIGHT not defined. Default: WINDOW_HEIGHT
    #pragma message "WINDOW_HEIGHT not defined. Default: " #WINDOW_HEIGHT
#endif


using std::string;


static void init_sdl()
{
    if(SDL_Init(SDL_INIT_VIDEO)) {
        string error = "Could not init SDL.\n";
        error += "SDL_Error: \n";
        error += SDL_GetError();
        throw std::runtime_error(error.c_str());
    }
}

#ifdef USE_SDL2_NET
static void init_sdl_net()
{
    if(SDLNet_Init()) {
        string error = "Could not init SDL.\n";
        error += "Net_Error: \n";
        error += SDLNet_GetError();
        throw std::runtime_error(error.c_str());
    }
}
#endif

#ifdef USE_SDL2_IMAGE
static void init_sdl_image()
{
    if(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)
        return;

    string error = "Could not init SDL.\n";
    error += "IMG_Error: \n";
    error += IMG_GetError();
    throw std::runtime_error(error.c_str());
}
#endif

#ifdef USE_SDL2_TTF
static void init_sdl_ttf()
{
    if(TTF_Init()) {
        string error = "Could not init SDL.\n";
        error += "TTF_Error: \n";
        error += TTF_GetError();
        throw std::runtime_error(error.c_str());
    }
}
#endif

static void create_window()
{
    core::window = SDL_CreateWindow(
        PROJECT_NAME,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        0
        //SDL_WINDOW_MOUSE_CAPTURE
        //| SDL_WINDOW_INPUT_GRABBED
    );

    if(!core::window) {
        string error = "Could not create window.\n";
        error += "SDL_Error: \n";
        error += SDL_GetError();
        throw std::runtime_error(error.c_str());
    }
}

static void create_renderer(bool vsync)
{
    core::renderer = SDL_CreateRenderer(
        core::window,
        -1,
        vsync ? SDL_RENDERER_PRESENTVSYNC : 0
    );

    if(!core::renderer) {
        string error = "Could not create renderer.\n";
        error += "SDL_Error: \n";
        error += SDL_GetError();
        throw std::runtime_error(error.c_str());
    }
}


void core::init_core(int argc, char** argv)
{
    init_sdl();
#ifdef USE_SDL2_NET
    init_sdl_net();
#endif
#ifdef USE_SDL2_IMAGE
    init_sdl_image();
#endif
#ifdef USE_SDL2_TTF
    init_sdl_ttf();
#endif

    bool vsync = false;
    for(int i = 1; i < argc; ++i) {
        if(strcmp(argv[i], "--vsync") == 0)
            vsync = true;

        if(strcmp(argv[i], "--no-vsync") == 0)
            vsync = false;
    }

    create_window();
    create_renderer(vsync);

    register_scenes();
    init_scenes(argc, argv);
}

void core::deinit_core()
{
    deinit_scenes();

    if(renderer)
        SDL_DestroyRenderer(renderer);
    if(window)
        SDL_DestroyWindow(window);

    window = nullptr;
    renderer = nullptr;

#ifdef USE_SDL2_TTF
    TTF_Quit();
#endif
#ifdef USE_SDL2_NET
    SDLNet_Quit();
#endif
#ifdef USE_SDL2_IMAGE
    IMG_Quit();
#endif
    SDL_Quit();
}
