#ifndef APP_H
#define APP_H

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class App {
    public:
        App();
        ~App();
        bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
        void handleEvents();
        void update();
        void render();
        void cleanup();
        bool running();

        static SDL_Renderer* renderer;
    private:
        bool SDL_init();
        bool isRunning;
        SDL_Window* window;

};

namespace Colors {
    const SDL_Color BLACK = {0,0,0,SDL_ALPHA_OPAQUE};
    const SDL_Color GREEN = {0,255,0,SDL_ALPHA_OPAQUE};
}

#endif