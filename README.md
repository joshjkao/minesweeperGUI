# sdl_minesweeper

A simple, incomplete version of minesweeper written in C++ using SDL2 and the code that was used for the minesweeper solving algorithm. This is a side project used to gain familiarity with SDL2 and get an introduction to C++ graphics.

Controls:
- Flag a square with SPACE
- Reveal a square with MOUSE1
- Reveal all neighbors with SPACE (on a square that is revealed and has the correct number of flags surrounding it)
- Restart the game with R

To compile the code, first you'll need the SDL2 library functions, which are available here: https://github.com/libsdl-org/

Note: The Makefile is configured based on the setup for arm64, so Windows users will likely need to edit the Makefile to point to the proper include and library paths.

Once everything is setup, run make to compile the program and ./build/debug/play to run it. 


Note 2: Jumpscare Warning! (intentional gameplay mechanic included to add suspense to the minesweeper experience)
