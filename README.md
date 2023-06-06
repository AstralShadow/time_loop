# Time Loop Duel

**The enemy brought a knife in a gunfight.**

**It's a time loop. In your favor.**

**But can you survive 3 duels?**

Play at [itch.io](https://azcraft.itch.io/time-loop-duel).


# Building
Dependencies:
 * C++17 compatible compiler (g++ is set in makefile)
 * [libSDL2](https://www.libsdl.org/)

## Linux

    $ git clone https://github.com/AstralShadow/time-loop.git
    $ cd time-loop
    $ make -j$(nproc)
    $ make run

## Web (Emscripten)
Install and prepare the
[Emscripten SDK](https://github.com/emscripten-core/emsdk).
Use make with makefile\_ems to compile the game.

    $ git clone https://github.com/AstralShadow/time-loop.git
    $ cd time-loop 
    $ make -j ${nrpoc} -f makefile_ems

Host `bin_ems` and open index.html in browser.

    $ cd bin_ems
    $ python -m http.server

## Windows and other
The game should work on any system supported by SDL2.
If that's not the case, open an issue or a pull request.

To compile the game you will have to
[Setup SDL](https://wiki.libsdl.org/SDL2/Installation)
and add all `.cpp` files in `src/` to your IDE of choice.

