#include "app.h"
#include "texturemanager.h"
#include "entity.h"
#include "texturemap.h"
#include "minesweeper.h"

SDL_Renderer* App::renderer = nullptr;
Entity* glasses = nullptr;
Entity* skull = nullptr;
Entity* background = nullptr;
TextureMap* map = nullptr;
Board* mines = new Board(16,30,99);

int mousex=0;
int mousey=0;

App::App():
isRunning(false), window(nullptr)
{

}

App::~App() {

}

bool App::SDL_init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0) {
        std::cout << "SDL_Init failed with error: " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

bool App::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    if(!SDL_init()) {
        cleanup();
        isRunning = false;
        return false; 
    }
    std::cout << "SDL initialized" << std::endl;
    window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_OPENGL);
    if (window == nullptr) {
        std::cout << "unable to create the main window with error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        isRunning = false;
        return false;
    }
    std::cout << "Window created" << std::endl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    std::cout << "Renderer created" << std::endl;
    isRunning = true;

    glasses = new Entity("assets/sunglasses.png",0,0);
    skull = new Entity("assets/skull.png",0,0);
    background = new Entity("assets/background.png",0,0);
    map = new TextureMap(mines->getOutput());
    

    return true;
}

void App::handleEvents() {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN: {
                isRunning = event.key.keysym.scancode != SDL_SCANCODE_ESCAPE;
                if (event.key.keysym.scancode == SDL_SCANCODE_SPACE) {
                    SDL_GetMouseState(&mousex, &mousey);
                    mines->flag(mousey/32-2, mousex/32-1);
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_R) {
                    mines->newGame();
                }
                break;
            }
            case SDL_QUIT: {
                isRunning = false;
                break;
            }
            case SDL_MOUSEBUTTONDOWN: {
                SDL_GetMouseState(&mousex, &mousey);
                // std::cout << "mouse 1 pressed on tile " << mousey/32 << " " << mousex/32 << std::endl;
                mines->dig(mousey/32-2, mousex/32-1);
                break;
            }
            default:
                break;
        }
    }
}

void App::update() {
    map->loadMap(mines->getOutput());
    if (mines->gameContinue() == 1) {
        glasses->update();
    }
    else if (mines->gameContinue() == -1) {
        skull->update();
    }
}

void App::render() {
    SDL_RenderClear(renderer);
    background->render();
    map->render();
    if (mines->gameContinue() == 1) {
        glasses->render();
    }
    if (mines->gameContinue() == -1) {
        skull->render();
    }
    SDL_RenderPresent(renderer);
}

void App::cleanup() {
    delete map;
    delete mines;
    delete glasses;
    delete skull;
    if (window != nullptr) {
        SDL_DestroyWindow(window);
        window = nullptr;
        std::cout << "Window destroyed" << std::endl;
    }
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer); 
        renderer = nullptr;
        std::cout << "Renderer destroyed" << std::endl;
    }
    
    SDL_Quit();
    std::cout << "SDL quit" << std::endl;
}

bool App::running() {
    return isRunning;
}